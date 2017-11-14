import game_framework
import title_state

from pico2d import *
from title import Title_Background, Character, Floor, Edge, Arrow
from zero_x3 import *
from kirby import *
from megaman_X import *

name = "CharacterList"

background = None
character = None
zero_x3 = None
kirby_ = None
megaman = None
floor = None
edge = None
arrow = None

def create_world():
    global background, character, zero_x3, kirby_, megaman, floor, edge, arrow
    background = Title_Background()
    character = Character()
    zero_x3 = Zero()
    kirby_ = Kirby()
    megaman = Megaman
    floor = Floor()
    edge = Edge()
    arrow = Arrow()

def destroy_world():
    global background, character, zero_x3, kirby_, megaman, floor, edge, arrow
    del(background)
    del(character)
    del(zero_x3)
    del(kirby_)
    del(megaman)
    del(floor)
    del(edge)
    del(arrow)

def enter():
    global zero_walk_on, kirby_walk_on, megaman_walk_on
    open_canvas()
    game_framework.reset_time()
    zero_walk_on = True
    kirby_walk_on = True
    megaman_walk_on = True
    create_world()

def exit():
    destroy_world()
    close_canvas()

def pause(): pass

def resume(): pass

def handle_events(frame_time):
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if (event.type, event.key) == (SDL_KEYDOWN, SDLK_ESCAPE):
                game_framework.pop_state()

def update(frame_time):
    pass

def draw(frame_time):
    clear_canvas()
    background.draw()
    character.draw()
    zero_x3.draw()
    kirby_.draw()

    megaman.draw()
    floor.draw()
    edge.draw()
    arrow.draw()

    update_canvas()