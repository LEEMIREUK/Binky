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

class C_Floor:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Floor.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class C_Edge:
    def __init__(self):
        self.image = load_image('Resource\\TitleImage\\Edge.png')

    def Draw(self, x, y):
        self.image.draw(x, y)

class Zero_x3:
    PIXEL_PER_METER_HEIGHT = (10.0 / 0.1)          #10 pixel 10 cm
    PIXEL_PER_METER_WIDTH = (10.0 / 0.1)           #10 pixel 10 cm
    MOVE_SPEED_KMPH = 2.0                          # Km / Hour
    MOVE_SPEED_MPM = (MOVE_SPEED_KMPH * 1000.0 / 60.0)
    MOVE_SPEED_MPS = (MOVE_SPEED_MPM / 60.0)
    MOVE_SPEED_PPS = (MOVE_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    JUMP_SPEED_KMPH = 3.0                          # Km / Hour
    JUMP_SPEED_MPM = (JUMP_SPEED_KMPH * 1000.0 / 60.0)
    JUMP_SPEED_MPS = (JUMP_SPEED_MPM / 60.0)
    JUMP_SPEED_PPS = (JUMP_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    FALL_SPEED_KMPH = 3.0                          # Km / Hour
    FALL_SPEED_MPM = (FALL_SPEED_KMPH * 1000.0 / 60.0)
    FALL_SPEED_MPS = (FALL_SPEED_MPM / 60.0)
    FALL_SPEED_PPS = (FALL_SPEED_MPS * PIXEL_PER_METER_HEIGHT)

    TIME_PER_ACTION = 0.5
    ACTION_PER_TIME = 1.0 / TIME_PER_ACTION
    FRAMS_PER_ACTION = 8

    def __init__(self):
        self.leftstopimage = load_image('Resource\\CharacterImage\\Zero\\Stop-Left.png')
        self.rightstopimage = load_image('Resource\\CharacterImage\\Zero\\Stop-Right.png')

        self.leftrunimage = load_image('Resource\\CharacterImage\\Zero\\Run-Left.png')
        self.rightrunimage = load_image('Resource\\CharacterImage\\Zero\\Run-Right.png')

        self.leftjumpimage = load_image('Resource\\CharacterImage\\Zero\\Jump-Left.png')
        self.rightjumpimage = load_image('Resource\\CharacterImage\\Zero\\Jump-Right.png')

        self.leftfallimage = load_image('Resource\\CharacterImage\\Zero\\Fall-Left.png')
        self.rightfallimage = load_image('Resource\\CharacterImage\\Zero\\Fall-Right.png')

        self.leftbulletimage = load_image('Resource\\CharacterImage\\Zero\\Bullet-Left.png')
        self.rightbulletimage = load_image('Resource\\CharacterImage\\Zero\\Bullet-Right.png')

    def LeftRunDraw(self, frame, x, y):
        self.leftrunimage.clip_draw(frame * 47, 0, 47, 46, x, y)

    def RightRunDraw(self, frame, x, y):
        self.rightrunimage.clip_draw(frame * 47, 0, 47, 46, x, y)

    def LeftStopDraw(self, x, y):
        self.leftstopimage.draw(x, y)

    def RightStopDraw(self, x, y):
        self.rightstopimage.draw(x, y)
    pass

class Kirby:
    PIXEL_PER_METER_HEIGHT = (10.0 / 0.1)          #10 pixel 10 cm
    PIXEL_PER_METER_WIDTH = (10.0 / 0.1)           #10 pixel 10 cm
    MOVE_SPEED_KMPH = 2.0                          # Km / Hour
    MOVE_SPEED_MPM = (MOVE_SPEED_KMPH * 1000.0 / 60.0)
    MOVE_SPEED_MPS = (MOVE_SPEED_MPM / 60.0)
    MOVE_SPEED_PPS = (MOVE_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    JUMP_SPEED_KMPH = 3.0                          # Km / Hour
    JUMP_SPEED_MPM = (JUMP_SPEED_KMPH * 1000.0 / 60.0)
    JUMP_SPEED_MPS = (JUMP_SPEED_MPM / 60.0)
    JUMP_SPEED_PPS = (JUMP_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    FALL_SPEED_KMPH = 3.0                          # Km / Hour
    FALL_SPEED_MPM = (FALL_SPEED_KMPH * 1000.0 / 60.0)
    FALL_SPEED_MPS = (FALL_SPEED_MPM / 60.0)
    FALL_SPEED_PPS = (FALL_SPEED_MPS * PIXEL_PER_METER_HEIGHT)

    TIME_PER_ACTION = 0.5
    ACTION_PER_TIME = 1.0 / TIME_PER_ACTION
    FRAMS_PER_ACTION = 8

    def __init__(self):
        self.leftstopimage = load_image('Resource\\CharacterImage\\Kirby\\Stop-Left.png')
        self.rightstopimage = load_image('Resource\\CharacterImage\\Kirby\\Stop-Right.png')

        self.leftrunimage = load_image('Resource\\CharacterImage\\Kirby\\Run-Left.png')
        self.rightrunimage = load_image('Resource\\CharacterImage\\Kirby\\Run-Right.png')

        self.leftjumpimage = load_image('Resource\\CharacterImage\\Kirby\\Jump-Left.png')
        self.rightjumpimage = load_image('Resource\\CharacterImage\\Kirby\\Jump-Right.png')

        self.leftfallimage = load_image('Resource\\CharacterImage\\Kirby\\Fall-Left.png')
        self.rightfallimage = load_image('Resource\\CharacterImage\\Kirby\\Fall-Right.png')

        self.leftbulletimage = load_image('Resource\\CharacterImage\\Kirby\\Bullet-Left.png')
        self.rightbulletimage = load_image('Resource\\CharacterImage\\Kirby\\Bullet-Right.png')

    def LeftRunDraw(self, frame, x, y):
        self.leftrunimage.clip_draw(frame * 28, 0, 28, 37, x, y)

    def RightRunDraw(self, frame, x, y):
        self.rightrunimage.clip_draw(frame * 28, 0, 28, 37, x, y)

    def LeftStopDraw(self, frame, x, y):
        self.leftstopimage.clip_draw(frame * 26, 0, 26, 31, x, y)

    def RightStopDraw(self, frame, x, y):
        self.rightstopimage.clip_draw(frame * 26, 0, 26, 31, x, y)
    pass


class Megaman:
    PIXEL_PER_METER_HEIGHT = (10.0 / 0.1)          #10 pixel 10 cm
    PIXEL_PER_METER_WIDTH = (10.0 / 0.1)           #10 pixel 10 cm
    MOVE_SPEED_KMPH = 2.0                          # Km / Hour
    MOVE_SPEED_MPM = (MOVE_SPEED_KMPH * 1000.0 / 60.0)
    MOVE_SPEED_MPS = (MOVE_SPEED_MPM / 60.0)
    MOVE_SPEED_PPS = (MOVE_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    JUMP_SPEED_KMPH = 3.0                          # Km / Hour
    JUMP_SPEED_MPM = (JUMP_SPEED_KMPH * 1000.0 / 60.0)
    JUMP_SPEED_MPS = (JUMP_SPEED_MPM / 60.0)
    JUMP_SPEED_PPS = (JUMP_SPEED_MPS * PIXEL_PER_METER_HEIGHT)
    FALL_SPEED_KMPH = 3.0                          # Km / Hour
    FALL_SPEED_MPM = (FALL_SPEED_KMPH * 1000.0 / 60.0)
    FALL_SPEED_MPS = (FALL_SPEED_MPM / 60.0)
    FALL_SPEED_PPS = (FALL_SPEED_MPS * PIXEL_PER_METER_HEIGHT)

    TIME_PER_ACTION = 0.5
    ACTION_PER_TIME = 1.0 / TIME_PER_ACTION
    FRAMS_PER_ACTION = 8

    def __init__(self):
        self.leftstopimage = load_image('Resource\\CharacterImage\\Megaman\\Stop-Left.png')
        self.rightstopimage = load_image('Resource\\CharacterImage\\Megaman\\Stop-Right.png')

        self.leftrunimage = load_image('Resource\\CharacterImage\\Megaman\\Run-Left.png')
        self.rightrunimage = load_image('Resource\\CharacterImage\\Megaman\\Run-Right.png')

        self.leftjumpimage = load_image('Resource\\CharacterImage\\Megaman\\Jump-Left.png')
        self.rightjumpimage = load_image('Resource\\CharacterImage\\Megaman\\Jump-Right.png')

        self.leftfallimage = load_image('Resource\\CharacterImage\\Megaman\\Fall-Left.png')
        self.rightfallimage = load_image('Resource\\CharacterImage\\Megaman\\Fall-Right.png')

    def LeftRunDraw(self, frame, x, y):
        self.leftrunimage.clip_draw(frame * 34, 0, 34, 35, x, y)

    def RightRunDraw(self, frame, x, y):
        self.rightrunimage.clip_draw(frame * 34, 0, 34, 35, x, y)

    def LeftStopDraw(self, x, y):
        self.leftstopimage.draw(x, y)

    def RightStopDraw(self, x, y):
        self.rightstopimage.draw(x, y)
    pass

