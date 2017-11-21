import game_framework
import game_title
from pico2d import *
from class_data import *


name = "GameLogo"

image = None
Game_Logo = None
logo_time = 0.0


def enter():
    global Game_Logo
    open_canvas(Canvas_Width, Canvas_Hight)
    Game_Logo = Logo()
    pass

def exit():
    global Game_Logo
    close_canvas()
    del(Game_Logo)
    pass

def update():
    global logo_time
    if(logo_time > 1.0):
        logo_time = 0
        game_framework.change_state(game_title)
    logo_time += 0.01

def draw():
    clear_canvas()
    Game_Logo.Draw()
    update_canvas()
    pass

def handle_events():
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if event.type == SDL_KEYDOWN and event.key == SDLK_ESCAPE:
               game_framework.quit()
    pass

def pause(): pass

def resume(): pass