from pico2d import *

class Logo:
    image = None
    def __init__(self):
        if Logo.image == None:
            Logo.image = load_image('Logo image.png')

    def draw(self):
        self.image.draw(400, 300)