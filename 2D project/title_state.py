import game_framework
import stage1
import character_list
from pico2d import *

from title import *

name = "TitleState"
background = None
game_title = None
arrow = None
start = None
character = None
help_ = None
exit_ = None
stage1_ = None
floor = None
help_text = None

def create_world():
    global background, game_title, arrow, start, character, exit_, help_, help_text, stage1_
    background = Title_Background()
    game_title = Game_Title()
    arrow = Arrow()
    start = Start()
    character = Character()
    help_ = Help()
    exit_ = Exit()
    stage1_ = Stage1()
    help_text = Help_Text()

def destroy_world():
    global background, game_title, arrow, start, character, exit_, help_, help_text, stage1_
    del(background)
    del(game_title)
    del(arrow)
    del(start)
    del(character)
    del(exit_)
    del(help_)
    del(help_text)
    del(stage1_)

def enter():
    open_canvas()
    game_framework.reset_time()
    create_world()

def exit():
    destroy_world()
    close_canvas()

def pause(): pass

def resume(): pass

def handle_events(frame_time):
    global select_list, select_mode, help_text_on, arrow_Y
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            arrow.handle_event(event)

def update(frame_time):
    background.update(frame_time)

def draw(frame_time):
    clear_canvas()
    background.draw()
    game_title.draw()
    arrow.draw()
#    if select_mode == 1:
    start.draw()
    character.draw()
    help_.draw()
    exit_.draw()
#        if help_text_on:
    help_text.draw()
#    elif select_mode == 2:
    stage1_.draw()
    update_canvas()