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
Floor = None
Edge = None

C_Zero = None
C_Kirby = None
C_Megaman = None

ScreenMode = 1
Arrow_LeftY = 230
Arrow_UpX = 280
HelpTextOn = False
Z_frame = 0 # 10
K_frame = 0 # 7
M_frame = 0 # 11
Select_Character = 1

def enter():
    global Title_Background, Title_Name, Title_Start, Title_Character, Title_Help, Title_HelpText, Title_Exit
    global Arrow_Left, Arrow_Up, Floor, Edge
    global C_Zero, C_Kirby, C_Megaman
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
    Floor = C_Floor()
    Edge = C_Edge()
    C_Zero = Zero_x3()
    C_Kirby = Kirby()
    C_Megaman = Megaman()
    pass

def exit():
    global Title_Background, Title_Name, Title_Start, Title_Character, Title_Help, Title_HelpText, Title_Exit
    global Arrow_Left, Arrow_Up, Floor, Edge
    global C_Zero, C_Kirby, C_Megaman
    close_canvas()
    del(Title_Background)
    del(Title_Name)
    del(Title_Start)
    del(Title_Character)
    del(Title_Help)
    del(Title_HelpText)
    del(Title_Exit)
    del(Arrow_Left)
    del(Arrow_Up)
    del(Floor)
    del(Edge)
    del(C_Zero)
    del(C_Kirby)
    del(C_Megaman)
    pass

def update():
    global ScreenMode
    global Z_frame, K_frame, M_frame
    if ScreenMode == 2:
        Z_frame = (Z_frame + 1) % 10
        K_frame = (K_frame + 1) % 7
        M_frame = (M_frame + 1) % 11
        delay(0.05)
    pass

def draw():
    clear_canvas()
    Title_Background.Draw()
    ###########################################
    # 기본 메인 화면
    if ScreenMode == 1:
        Title_Name.Draw(400, 500)
        if not HelpTextOn:
            Title_Start.Draw(400, 230)
            Title_Character.Draw(400, 170)
            Title_Help.Draw(400, 110)
            Title_Exit.Draw(400, 50)
            Arrow_Left.LeftDraw(670, Arrow_LeftY)
        if HelpTextOn:
            Title_HelpText.Draw(400, 200)
    ###########################################
    # 캐릭터 선택 화면
    elif ScreenMode == 2:
        Arrow_Up.UpDraw(Arrow_UpX, 120)
        Floor.Draw(400, 170)
        Edge.Draw(400, 400)
        C_Zero.RightRunDraw(Z_frame, 280, 209)
        C_Kirby.RightRunDraw(K_frame, 400, 204)
        C_Megaman.RightRunDraw(M_frame, 520, 203)
        if Select_Character == 1:
            C_Zero.RightStopDraw(400, 400)
        elif Select_Character == 2:
            C_Kirby.RightStopDraw((K_frame % 2), 400, 400)
        elif Select_Character == 3:
            C_Megaman.RightStopDraw(400, 400)
        pass

    update_canvas()
    pass

def handle_events():
    global ScreenMode, HelpTextOn
    global Arrow_LeftY, Arrow_UpX
    global Select_Character
    events = get_events()
    for event in events:
        if event.type == SDL_QUIT:
            game_framework.quit()
        else:
            if event.type == SDL_KEYDOWN and event.key == SDLK_ESCAPE:
                if ScreenMode == 1:
                    if HelpTextOn:
                        HelpTextOn = False
                    elif not HelpTextOn:
                       game_framework.quit()
                elif ScreenMode == 2:
                    ScreenMode = 1
            elif event.type == SDL_KEYDOWN and event.key == SDLK_DOWN:
                if ScreenMode == 1 and not HelpTextOn:
                    Arrow_LeftY -= 60
                    if Arrow_LeftY == -10:
                        Arrow_LeftY = 230
            elif event.type == SDL_KEYDOWN and event.key == SDLK_UP:
                if ScreenMode == 1 and not HelpTextOn:
                    Arrow_LeftY += 60
                    if Arrow_LeftY == 290:
                        Arrow_LeftY = 50
            elif event.type == SDL_KEYDOWN and event.key == SDLK_SPACE:
                if ScreenMode == 1 and not HelpTextOn:
                    if Arrow_LeftY == 230:
                        pass
                    elif Arrow_LeftY == 170:
                        ScreenMode = 2
                    elif Arrow_LeftY == 110:
                        HelpTextOn = True
                    elif Arrow_LeftY == 50:
                        game_framework.quit()
                elif ScreenMode == 2 and not HelpTextOn:
                    if Arrow_UpX == 280:
                        Select_Character = 1
                    elif Arrow_UpX == 400:
                        Select_Character = 2
                    elif Arrow_UpX == 520:
                        Select_Character = 3
            elif event.type == SDL_KEYDOWN and event.key == SDLK_RIGHT:
                if ScreenMode == 2 and not HelpTextOn:
                    Arrow_UpX += 120
                    if Arrow_UpX == 640:
                        Arrow_UpX = 280
            elif event.type == SDL_KEYDOWN and event.key == SDLK_LEFT:
                if ScreenMode == 2 and not HelpTextOn:
                    Arrow_UpX -= 120
                    if Arrow_UpX == 160:
                        Arrow_UpX = 520
    pass

def pause(): pass

def resume(): pass