from pico2d import *

megaman_walk_on = False

class Megaman:
    PIXEL_PER_METER = (10.0 / 0.1)           #10 pixel 10 cm
    RUN_SPEED_KMPH = 10.0                    # Km / Hour
    RUN_SPEED_MPM = (RUN_SPEED_KMPH * 1000.0 / 60.0)
    RUN_SPEED_MPS = (RUN_SPEED_MPM / 60.0)
    RUN_SPEED_PPS = (RUN_SPEED_MPS * PIXEL_PER_METER)

    TIME_PER_ACTION = 0.5
    ACTION_PER_TIME = 1.0 / TIME_PER_ACTION
    FRAMS_PER_ACTION = 8

    RIGHT_RUN, LEFT_RUN, RIGHT_JUMP, LEFT_JUMP, RIGHT_FALL, LEFT_FALL = 0, 35, 70, 116, 162, 203
    RIGHT_STAND, LEFT_STAND, RIGHT_SHOOT, LEFT_SHOOT, RIGHT_BULLET, LEFT_BULLET = 244, 278, 312, 346, 380, 411

    image = None
    def __init__(self):
        self.x, self.y = 0, 40
        self.life_time = 0.0
        self.total_frames = 0.0
        self.state = self.RIGHT_STAND
        self.frame = 0
        self.dir = 0
        if Megaman.image == None:
            Megaman.image = load_image('Megaman animation.png')

    def update(self, frame_time):
        def clamp(minimum, x, maximun):
            return max(minimum, min(x, maximun))

        self.life_time += frame_time
        distance = Megaman.RUN_SPEED_PPS * frame_time
        self.total_frames += Megaman.FRAMS_PER_ACTION * Megaman.ACTION_PER_TIME * frame_time
        self.walk_frame = int(self.total_frames) % 11
        self.frame = int(self.total_frames) % 8
        self.x += (self.dir * distance)

        self.x = clamp(0, self.x, 800)

    def draw(self):
        global megaman_walk_on
        if megaman_walk_on:
            self.image.clip_draw(self.walk_frame * 34, 0, 34, 35, 520, 175)

    def handle_event(self, event):
        if (event.type, event.key) == (SDL_KEYDOWN, SDLK_LEFT):
            if self.state in (self.RIGHT_STAND, self.LEFT_STAND, self.RIGHT_RUN):
                self.state = self.LEFT_RUN
                self.dir = -1
        elif (event.type, event.key) == (SDL_KEYDOWN, SDLK_RIGHT):
            if self.state in (self.RIGHT_STAND, self.LEFT_STAND, self.LEFT_RUN):
                self.state = self.RIGHT_RUN
                self.dir = 1
        elif (event.type, event.key) == (SDL_KEYUP, SDLK_LEFT):
            if self.state in (self.LEFT_RUN,):
                self.state = self.LEFT_STAND
                self.dir = 0
        elif (event.type, event.key) == (SDL_KEYUP, SDLK_RIGHT):
            if self.state in (self.RIGHT_RUN,):
                self.state = self.RIGHT_STAND
                self.dir = 0

