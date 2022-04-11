import os
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
import time
import requests

URL = 'https://passport.mingrisoft.com/login/index.html'

header = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36"
}

wb=webdriver.Chrome()
wb.get(URL)
wb.implicitly_wait(10)
a=input("waiting")
