from pynput import mouse,keyboard
import time

for i in range(5):
    time.sleep(1)
    print(i)
for i in range(400):
    time.sleep(0.5)
    m_keyboard = keyboard.Controller()
    m_keyboard.press(keyboard.Key.right)
    m_keyboard.release(keyboard.key.right)