import game_framework
import stage1
import character_list
import random
from pico2d import *

name = "TitleState"
help_text_on = False
select_list = 1
select_mode = 1

class Title_Background:
    image = None
    def __init__(self):
        self.effect_time = 0
        self.opacify_num = 1
        if Title_Background.image == None:
            Title_Background.image = load_image('Title background image.png')

    def update(self, frame_time):
        if self.effect_time > 1.0:
            self.opacify_num = 0
            effect_time = 0
        else:
            self.effect_time += 0.05
            self.opacify_num = 0

    def draw(self):
        self.image.opacify(self.opacify_num)
        self.image.draw(400, 300)

class Game_Title:
    image = None
    def __init__(self):
        if Game_Title.image == None:
            Game_Title.image = load_image('Game title image.png')

    def draw(self):
        self.image.draw(400, 500)

class Arrow:
    image = None
    def __init__(self):
        self.arrow_Y = 230
        self.x, self.y = 670, 230
        if Arrow.image == None:
            Arrow.image = load_image('Arrow image.png')

    def draw(self):
        self.image.draw(self.x, self.arrow_Y)

    def update(self, frame_time): pass

    def handle_event(self, event):
        global select_list, select_mode, help_text_on
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if (event.type, event.key) == (SDL_KEYDOWN, SDLK_ESCAPE):
                 if not help_text_on:
                    if select_mode == 1:
                        game_framework.quit()
                    elif select_mode == 2:
                        select_mode =1
            elif (event.type, event.key) == (SDL_KEYDOWN, SDLK_DOWN):
                if not help_text_on:
                    if select_mode == 1:
                        self.arrow_Y -= 60
                        select_list += 1
                        if self.arrow_Y == -10:
                            self.arrow_Y = 230
                            select_list = 1
            elif (event.type, event.key) == (SDL_KEYDOWN, SDLK_UP):
                if not help_text_on:
                    if select_mode == 1:
                        self.arrow_Y += 60
                        select_list -= 1
                        if self.arrow_Y == 290:
                            self.arrow_Y = 50
                            select_list = 4
            elif (event.type, event.key) == (SDL_KEYDOWN, SDLK_SPACE):
                if select_mode == 1:
                    if select_list == 1:
                        select_mode = 2
                    elif select_list == 2:
                        game_framework.push_state(character_list)

                    elif select_list == 3:
                        if not help_text_on:
                            help_text_on = True
                        else:
                            help_text_on = False
                    elif select_list == 4:
                        game_framework.quit()
                elif select_mode == 2 and select_list == 1:
                    game_framework.push_state(stage1)
                    select_list = 1
                    select_mode = 1

class Start:
    image = None
    def __init__(self):
        if Start.image == None:
            Start.image = load_image('Start image.png')

    def draw(self):
        if select_mode == 1:
            self.image.draw(400, 230)

class Character:
    image = None
    def __init__(self):
        if Character.image == None:
            Character.image = load_image('Character image.png')

    def draw(self):
        if select_mode == 1:
            self.image.draw(400, 170)

class Help:
    image = None
    def __init__(self):
        if Help.image == None:
            Help.image = load_image('Help image.png')

    def draw(self):
        if select_mode == 1:
            self.image.draw(400, 110)

    def handle_event(self, event):
        global help_text_on
        if select_list == 3:
            if not help_text_on:
                help_text_on = True
            else:
                help_text_on = False

class Exit:
    image = None
    def __init__(self):
        if Exit.image == None:
            Exit.image = load_image('Exit image.png')

    def draw(self):
        if select_mode == 1:
            self.image.draw(400, 50)

class Stage1:
    image = None
    def __init__(self):
        if Stage1.image == None:
            Stage1.image = load_image('Stage1 image.png')

    def draw(self):
        if select_mode == 2:
            self.image.draw(400, 230)

class Help_Text:
    image = None
    def __init__(self):
        if Help_Text.image == None:
            Help_Text.image = load_image('Help text image.png')

    def draw(self):
        global help_text_on
        if help_text_on:
            self.image.draw(400,200)

class Floor:
    image = None
    def __init__(self):
        if Floor.image == None:
            Floor.image = load_image('Character floor image.png')

    def draw(self):
        self.image.draw(400, 150)

class Edge:
    image = None
    def __init__(self):
        if Edge.image == None:
            Edge.image = load_image('Edge image.png')

    def draw(self):
        self.image.draw(400, 350)