# meta-simplegui/recipes-gui/simplegui/simplegui.py

import tkinter as tk

def say_hello():
    label.config(text="Hello, Yocto GUI!")

root = tk.Tk()
root.title("Yocto Simple GUI")

label = tk.Label(root, text="Click the button to greet Yocto!")
label.pack(pady=10)

button = tk.Button(root, text="Greet", command=say_hello)
button.pack()

root.mainloop()
