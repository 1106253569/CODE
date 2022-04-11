import requests
from Crypto.Cipher import AES

url = "https://music.163.com/weapi/comment/resource/comments/get?csrf_token="

data = {
    "csrf_token": "",
    "cursor": "-1",
    "offset": "0",
    "orderType": "1",
    "pageNo": "1",
    "pageSize": "20",
    "rid": "R_SO_4_1325905146",
    "threadId": "R_SO_4_1325905146"
}

f = "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7"
requests.post(url)
'''
function a(a) {
        var d, e, b = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", c = "";
        for (d = 0; a > d; d += 1)
            e = Math.random() * b.length,
            e = Math.floor(e),
            c += b.charAt(e);
        return c
    }
    function b(a, b) {
        var c = CryptoJS.enc.Utf8.parse(b)
          , d = CryptoJS.enc.Utf8.parse("0102030405060708")
          , e = CryptoJS.enc.Utf8.parse(a)
          , f = CryptoJS.AES.encrypt(e, c, {
            iv: d,
            mode: CryptoJS.mode.CBC
        });
        return f.toString()
    }
    function c(a, b, c) {
        var d, e;
        return setMaxDigits(131),
        d = new RSAKeyPair(b,"",c),
        e = encryptedString(d, a)
    }
    function d(d, e, f, g) {
        var h = {}
          , i = a(16);
        return h.encText = b(d, g),
        h.encText = b(h.encText, i),
        h.encSecKey = c(i, e, f),
        h
    }
'''
e = "010001"
f = "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7"
g = "0CoJUm6Qyw8W8jud"
i = "05c7WD13prDFhfYC"
encSeckey = "22d7cb9a6749ddc07f83e311c4bcf1ad20d00e1177b81aa0c7ee03a2e572f1cde68201ce6bb2880c35b4249793169651087aa462c80260ce41bf4e0c9ef9c932b2e964639b8b252e0945b361f56ef01966d7623780076e7059d89b8a322706cf6e046c866314340368a04179882fc43d8a8c7ab91ecfeaf3d4feb66ddc8511e3"


def get_encSeckey():
    return "22d7cb9a6749ddc07f83e311c4bcf1ad20d00e1177b81aa0c7ee03a2e572f1cde68201ce6bb2880c35b4249793169651087aa462c80260ce41bf4e0c9ef9c932b2e964639b8b252e0945b361f56ef01966d7623780076e7059d89b8a322706cf6e046c866314340368a04179882fc43d8a8c7ab91ecfeaf3d4feb66ddc8511e3"


def get_params(data):
    first = enc_params(data, g)
    second = enc_params(first, i)
    return second


def enc_params(data, key):
    pass