import random
import json
import os

from pico2d import *

import game_framework
import title_state


name = "Stage1"
zero_x3 = None
kirby = None
megaman = None

class Zero_x3:
    def __init__(self):
        self.x, self.y = 50, 90
        self.frame = 0
        self.state = self.RIGHT_STAND

        if Zero_x3.image == None:
            Zero_x3.image = load_image('zero x3 animation.png')

    def draw(self):
        self.image.draw(280, 182)

class Kirby:
    def __init__(self):
        self.frame = 0
        self.image = load_image('Kirby stop sprite image.png')

    def update(self):
        self.frame = (self.frame + 1) % 2
        delay(0.1)

    def draw(self):
        self.image.clip_draw(self.frame * 26, 0, 26, 31, 400, 175)

class Megaman:
    def __init__(self):
        self.image = load_image('Megaman X stop image.png')

    def draw(self):
        self.image.draw(520, 177)

def enter():
    global zero_x3, kirby, megaman
    zero_x3 = Zero_x3()
    kirby = Kirby()
    megaman = Megaman()

def exit():
    global zero_x3, kirby, megaman
    del(zero_x3)
    del(kirby)
    del(megaman)

def handle_events():
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if(event.type, event.key) == (SDL_KEYDOWN, SDLK_ESCAPE):
                game_framework.change_state(title_state)

def draw():
    clear_canvas()
    update_canvas()
    pass


def update():
    pass


def pause():
    pass


def resume():
    pass





