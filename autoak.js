// ==UserScript==
// @name         自动AK机
// @namespace    http://tampermonkey.net/
// @version      1.1
// @description  LET'S AK BY CTJ!
// @author       null
// @match        *://*.xmoj.tech/problem.php*
// @grant        GM_notification
// @grant        GM_xmlhttpRequest
// @grant        GM_setClipboard
// ==/UserScript==

(function() {
    'use strict';

    // 创建UI元素
    function createUI() {
        // 容器
        const container = document.createElement('div');
        container.id = 'code-fetcher-container';
        container.style.cssText = `
            position: fixed;
            top: 20px;
            right: 20px;
            background: white;
            border: 2px solid #007bff;
            border-radius: 8px;
            padding: 15px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.15);
            z-index: 999999;
            font-family: Arial, sans-serif;
            min-width: 250px;
            max-width: 300px;
        `;

        // 标题
        const title = document.createElement('h3');
        title.textContent = '自动AK机';
        title.style.cssText = `
            margin: 0 0 10px 0;
            color: #007bff;
            font-size: 16px;
        `;

        // 输入框
        const input = document.createElement('input');
        input.type = 'text';
        input.placeholder = '输入题号 (如: 1000 或 10000)';
        input.id = 'problem-input';
        input.style.cssText = `
            width: 100%;
            padding: 8px;
            margin-bottom: 10px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
            font-size: 14px;
        `;

        // 按钮
        const button = document.createElement('button');
        button.textContent = '自动AK';
        button.id = 'fetch-button';
        button.style.cssText = `
            width: 100%;
            padding: 10px;
            background: #007bff;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 14px;
            font-weight: bold;
            transition: background 0.3s;
        `;

        button.onmouseover = () => button.style.background = '#0056b3';
        button.onmouseout = () => button.style.background = '#007bff';

        // 状态显示
        const status = document.createElement('div');
        status.id = 'fetch-status';
        status.style.cssText = `
            margin-top: 10px;
            font-size: 12px;
            color: #666;
            min-height: 16px;
        `;

        // 关闭按钮
        const closeBtn = document.createElement('button');
        closeBtn.textContent = '×';
        closeBtn.style.cssText = `
            position: absolute;
            top: 5px;
            right: 8px;
            background: none;
            border: none;
            font-size: 20px;
            cursor: pointer;
            color: #999;
            padding: 0;
            width: 20px;
            height: 20px;
            line-height: 1;
        `;
        closeBtn.onclick = () => container.style.display = 'none';

        // 组装
        container.appendChild(closeBtn);
        container.appendChild(title);
        container.appendChild(input);
        container.appendChild(button);
        container.appendChild(status);
        document.body.appendChild(container);

        // 绑定事件
        button.onclick = fetchAndCopy;
        input.onkeypress = (e) => {
            if (e.key === 'Enter') fetchAndCopy();
        };
    }

    // 获取并复制代码
    async function fetchAndCopy() {
        const input = document.getElementById('problem-input');
        const status = document.getElementById('fetch-status');
        const button = document.getElementById('fetch-button');
        const problemId = input.value.trim();

        // 验证输入：允许4位或5位数字
        if (!/^\d{4,5}$/.test(problemId)) {
            status.textContent = '请输入4位或5位题号';
            status.style.color = '#dc3545';
            return;
        }

        const num = parseInt(problemId);
        if (num < 1000) {
            status.textContent = '题号不能小于1000';
            status.style.color = '#dc3545';
            return;
        }

        // 直接使用新的URL格式
        const url = `https://xmak.cc.cd/files/${problemId}.cpp`;

        // 显示加载状态
        button.disabled = true;
        button.textContent = '获取中...';
        status.textContent = `正在获取: ${url}`;
        status.style.color = '#666';

        try {
            // 发送请求
            const code = await fetchCode(url);

            if (code) {
                // 复制到剪贴板
                await GM_setClipboard(code, 'text');

                status.textContent = '代码已复制到剪贴板！';
                status.style.color = '#28a745';

                // 可选：显示通知
                GM_notification({
                    text: `题号 ${problemId} 的代码已复制到剪贴板`,
                    title: '代码获取器',
                    timeout: 3000
                });
            }
        } catch (error) {
            status.textContent = '请短消息联系 @null';
            status.style.color = '#dc3545';

            // 可选：显示通知
            GM_notification({
                text: `未找到题号 ${problemId} 的代码，请联系 @null获取`,
                title: '自动AK机',
                timeout: 4000
            });
        } finally {
            // 恢复按钮状态
            button.disabled = false;
            button.textContent = '自动AK';
        }
    }

    // 获取代码内容
    function fetchCode(url) {
        return new Promise((resolve, reject) => {
            GM_xmlhttpRequest({
                method: 'GET',
                url: url,
                onload: function(response) {
                    if (response.status === 200) {
                        resolve(response.responseText);
                    } else {
                        reject(new Error(`HTTP ${response.status}`));
                    }
                },
                onerror: function(error) {
                    reject(error);
                },
                timeout: 10000 // 10秒超时
            });
        });
    }

    // 初始化
    function init() {
        // 等待页面加载完成
        if (document.body) {
            createUI();
        } else {
            window.addEventListener('DOMContentLoaded', createUI);
        }
    }

    // 启动脚本
    init();
})();
