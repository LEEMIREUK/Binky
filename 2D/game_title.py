import game_framework
from pico2d import *
from class_data import *

name = "GameTitle"

Title_Background = None
Title_Name = None
Title_Start = None
Title_Character = None
Title_Help = None
Title_HelpText = None
Title_Exit = None
Arrow_Left = None
Arrow_Up = None
Arrow_LeftY = 230
HelpTextOn = False


def enter():
    global Title_Background, Title_Name, Title_Start, Title_Character, Title_Help, Title_HelpText, Title_Exit
    global Arrow_Left, Arrow_Up
    open_canvas()
    Title_Background = BackGround()
    Title_Name = Title()
    Title_Start = T_Start()
    Title_Character = T_Character()
    Title_Help = T_Help()
    Title_HelpText = T_HelpText()
    Title_Exit = T_Exit()
    Arrow_Left = Arrow()
    Arrow_Up = Arrow()
    pass

def exit():
    global Title_Background, Title_Name, Title_Start, Title_Character, Title_Help, Title_HelpText, Title_Exit
    global Arrow_Left, Arrow_Up
    del(Title_Background)
    del(Title_Name)
    del(Title_Start)
    del(Title_Character)
    del(Title_Help)
    del(Title_HelpText)
    del(Title_Exit)
    del(Arrow_Left)
    del(Arrow_Up)
    pass

def update():
    pass

def draw():
    clear_canvas()
    Title_Background.Draw()
    Title_Name.Draw(400, 500)
    Title_Start.Draw(400, 230)
    Title_Character.Draw(400, 170)
    Title_Help.Draw(400, 110)
    if HelpTextOn:
        Title_HelpText.Draw(400, 200)
    Title_Exit.Draw(400, 50)
    Arrow_Left.LeftDraw(670, Arrow_LeftY)
    update_canvas()
    pass

def handle_events():
    global Arrow_LeftY
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if event.type == SDL_KEYDOWN and event.key == SDLK_ESCAPE:
               game_framework.quit()
            elif event.type == SDL_KEYDOWN and event.key == SDLK_DOWN:
                Arrow_LeftY -= 60
                if Arrow_LeftY == -10:
                    Arrow_LeftY = 230
            elif event.type == SDL_KEYDOWN and event.key == SDLK_UP:
                Arrow_LeftY += 60
                if Arrow_LeftY == 290:
                    Arrow_LeftY = 50
    pass

def pause(): pass

def resume(): pass