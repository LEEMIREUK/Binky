import game_framework
import title_state

from pico2d import *
from logo import Logo

name = "LogoState"

logo = None
logo_time = 0

def create_world():
    global logo
    logo = Logo()

def destroy_world():
    global logo
    del(logo)

def enter():
    open_canvas()
    game_framework.reset_time()
    create_world()

def exit():
    destroy_world()
    close_canvas()

def pause():
    pass

def resume():
    pass

def handle_events(frame_time):
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if (event.type, event.key) == (SDL_KEYDOWN, SDLK_ESCAPE):
                game_framework.quit()

def update(frame_time):
    global logo_time
    if logo_time > 1.0:
        logo_time = 0
        game_framework.change_state(title_state)

    logo_time += 0.05

def draw(frame_time):
    clear_canvas()
    logo.draw()
    update_canvas()