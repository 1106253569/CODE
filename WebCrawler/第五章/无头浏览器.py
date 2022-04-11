from webbrowser import Chrome
from selenium.webdriver import chrome
from selenium.webdriver.chrome.options import Options

web=Chrome()

opt=Options()
opt.add_argument("--headlass")
opt.add_argument("--disable-gpu")