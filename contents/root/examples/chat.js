/* Copyright (c) 2012 Silk Project.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Silk nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL SILK BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

function connect(url) {
    if ("WebSocket" in window) {
        ws = new WebSocket(url, ["chat"]);
    } else if ("MozWebSocket" in window) {
        ws = new MozWebSocket(url, ["chat"]);
    }
    ws.onopen = function() {
        if (document.getElementById('name').value.length === 0) {
            document.getElementById('name').focus();
        } else {
            document.getElementById('message').focus();
        }
    }
    ws.onmessage = function(message) {
        addItem(JSON.parse(message.data));
    }
}

function post() {
    var input = document.getElementById('message');
    if (document.getElementById('name').value.length === 0) {
        document.getElementById('name').focus();
    } else if (input.value.length === 0) {
        input.focus();
    } else {
        var message = {};
        message.action = "post";
        message.user = document.getElementById('name').value;
        message.message = input.value;
        ws.send(JSON.stringify(message));
        input.value = '';
        input.focus();
    }
}

function addItem(data) {
    var dl = document.getElementById("dl");

    var dd = document.createElement("dd");
    dd.innerHTML = data.message
    if (dl.children.length > 2) {
        dl.insertBefore(dd, dl.children[2])
    } else {
        dl.appendChild(dd)
    }

    var dt = document.createElement("dt");
    dt.innerHTML = data.user
    dl.insertBefore(dt, dd)
}
