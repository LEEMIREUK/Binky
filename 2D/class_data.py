
from game_main import *
from pico2d import *
import os


name = "ClassData"

class Logo:
    def __init__(self):
        self.image = load_image('Resource\\BackgroundImage\\Logo.png')

    def Draw(self):
        self.image.draw_to_origin(0, 0, Canvas_Width, Canvas_Hight)

class BackGround:
    def __init__(self):
        self.image = load_image('Resource\\BackgroundImage\\Background.png')

    def Draw(self):
        self.image.draw_to_origin(0, 0, Canvas_Width, Canvas_Hight)

class Title:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Title.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class Arrow:
    def __init__(self):
        self.left = load_image('Resource\\TitleImage\\Arrow-Left.png')
        self.up = load_image('Resource\\TitleImage\\Arrow-Up.png')

    def LeftDraw(self, x, y):
        self.left.draw(x, y)

    def UpDraw(self, x, y):
        self.up.draw(x, y)

class T_Start:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Start.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class T_Character:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Character.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class T_Help:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Help.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class T_HelpText:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Help-Text.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class T_Exit:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Exit.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

