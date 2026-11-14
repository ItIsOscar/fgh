#include <stdio.h>
#define PADDLE_SMB "║"
#define BALL_SMB "0"
#define BKGRND_NONE " "
#define BKGRND_LOW "░"
#define BKGRND_HIGH "▓"
#define HRZ_LINE "─"
#define VRT_LINE "│"
#define LT_ANGLE "┌"
#define LB_ANGLE "└"
#define RT_ANGLE "┐"
#define RB_ANGLE "┘"

#define Y_SPC_SPR_SCOPE 2
#define X_SPR_SCOPE 40
#define Y_SPC_SCOPE 1
#define X_FRS_SCOPE 38
#define X_SCD_SCOPE 42

#define START_CRD_Y_PLAYER 11

#define MAX_HEIGHT 25
#define MAX_WIDHT 80

int CRD_FRT_PLAYER;
int MV_FRT_PLAYER;
int SCP_FRT_PLAYER;
int CRD_SCD_PLAYER;
int MV_SCD_PLAYER;
int SCP_SCD_PLAYER;

int y_ball;
int x_ball;
int y_vector;
int x_vector;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int modul(int x) {
    return x > 0 ? x : -x;
}

void grt1Y(int x) {
     switch(x) {
        case 1:
            printf(LT_ANGLE);
            break;
        case MAX_WIDHT:
            printf(RT_ANGLE);
            break;
        default:
            printf(HRZ_LINE);
     }
}

void grtMAXY(int x) {
    switch(x) {
        case 1:
            printf(LB_ANGLE);
            break;
        case MAX_WIDHT:
            printf(RB_ANGLE);
            break;
        default:
            printf(HRZ_LINE);
     }
}

void grtScope(int x) {
    switch (x)
    {
    case 1:
        printf(VRT_LINE);
        break;
    case X_FRS_SCOPE:
        printf("%d", SCP_FRT_PLAYER);
        break;
    case X_SPR_SCOPE:
        printf(VRT_LINE);
        break;
    case X_SCD_SCOPE:
        printf("%d", SCP_SCD_PLAYER);
        break;
    case MAX_WIDHT:
        printf(VRT_LINE);
    default:
        printf(BKGRND_NONE);
        break;
    }
}

void grtScopeLine(int x) {
    switch (x)
    {
    case 1:
        printf(LB_ANGLE);
        break;
    case MAX_WIDHT:
        printf(RB_ANGLE);
        break;
    default:
        printf(HRZ_LINE);
        break;
    }
}

void grtFirstPlayer(int y) {
    if(y == CRD_FRT_PLAYER || y == CRD_FRT_PLAYER + 1 || y == CRD_FRT_PLAYER + 2) {
        printf(PADDLE_SMB);
    }
    else {
        printf(BKGRND_NONE);
    }
}

void grtSecondPlayer(int y) {
    if(y == CRD_SCD_PLAYER || y == CRD_SCD_PLAYER + 1 || y == CRD_SCD_PLAYER + 2) {
        printf(PADDLE_SMB);
    }
    else {
        printf(BKGRND_NONE);
    }
}

void generatePixel(int y, int x) {
    if(y == y_ball && x == x_ball) {
        printf(BALL_SMB);
    }
    else {
        switch (y)
        {
        case 1:
            grt1Y(x);
            break;
        
        case MAX_HEIGHT:
            grtMAXY(x);
            break;
        case MAX_HEIGHT + Y_SPC_SCOPE:
            grtScope(x);
            break;
        case MAX_HEIGHT + Y_SPC_SPR_SCOPE:
            grtScopeLine(x);
            break;
        default: 
            switch (x)
            {
            case 1:
                printf(VRT_LINE);
                break;
            case 2:
                grtFirstPlayer(y);
                break;
            case X_SPR_SCOPE:
                printf(VRT_LINE);
                break;
            case MAX_WIDHT - 1:
                grtSecondPlayer(y);
                break;
            case MAX_WIDHT:
                printf(VRT_LINE);
                break;
            default:
                printf(BKGRND_NONE);
                break;
            }
        }
    }
}

void generateFrame() {
    for(int y = 1; y <= MAX_HEIGHT + Y_SPC_SPR_SCOPE; y++) {
        for(int x = 1; x <= MAX_WIDHT; x++) {
            generatePixel(y, x);
        }
        printf("\n");
    }
}

void initVector(int* ptr_y_vector, int* ptr_x_vector) {
    *ptr_y_vector = 1;
    if(SCP_FRT_PLAYER + SCP_SCD_PLAYER % 2 == 0) {
        *ptr_x_vector = 2;
        *ptr_y_vector = 1;
    }
    else {
        *ptr_y_vector = -2;
    }
    return;
}

int isOnBorderY() {
    int result = 0;
    if(y_ball == 2 || y_ball == MAX_HEIGHT - 1) {
        result = 1;
    }
    return result;
}

int isAbroatY() {
    int result = 0;
    if(y_ball + y_ball < 2 || y_ball + y_vector > MAX_HEIGHT - 1) {
        result = 1;
    }
    return result;
}

void moveBall() {
    int is_on_border_y = 0;
    if(isAbroatY()) {

    }
    else {
        y_ball = y_ball + y_vector;
        x_ball = x_ball + x_vector;
        if(isOnBorderY()) {
            y_vector = (-1) * y_vector;
            is_on_border_y = 1;
        }
    }
    int is_on_paddle_y = 0;
    if()
}

void movePlayer() {
    CRD_FRT_PLAYER = min(MAX_HEIGHT - 3, max(2, CRD_FRT_PLAYER + MV_FRT_PLAYER));
    CRD_SCD_PLAYER = min(MAX_HEIGHT - 3, max(2,  CRD_SCD_PLAYER + MV_SCD_PLAYER));
}

int readMove() {
    char cmd;
    int status = 1, is_frt_move = 0, is_scd_move = 0;
    while(scanf("%c", &cmd) == 1) {
        if(cmd == '\n') break;
        if(cmd == ' ');
        else if(cmd == 'A') {
            if(is_frt_move == 1) {
                status = 0;
            }
            is_frt_move = 1;
            MV_FRT_PLAYER = -1;
        }
        else if(cmd == 'Z') {
            if(is_frt_move == 1) {
                status = 0;
            }
            is_frt_move = 1;
            MV_FRT_PLAYER = 1;
        }
        else if(cmd == 'K') {
            if(is_scd_move == 1) {
                status = 0;
            }
            is_scd_move = 1;
            MV_SCD_PLAYER = -1;
        }
        else if(cmd == 'M') { 
            if(is_scd_move == 1) {
                status = 0;
            }
            is_scd_move = 1;
            MV_SCD_PLAYER = 1;
        }
        else {
            status = 0;
        }
        if(status == 0) {
            MV_FRT_PLAYER = 0;
            MV_SCD_PLAYER = 0;
            printf("INPUT ERROR!\n");
            cmd = '\n';
        }
    }
    return status;
}

void startGame() {
    char cmd;
    CRD_FRT_PLAYER = START_CRD_Y_PLAYER;
    MV_FRT_PLAYER = 0;
    SCP_FRT_PLAYER = 0;
    CRD_SCD_PLAYER = START_CRD_Y_PLAYER;
    MV_SCD_PLAYER = 0;
    SCP_SCD_PLAYER = 0;
    y_ball = 13;
    x_ball = 40;
    initVector(&y_vector, &x_vector);
    generateFrame(y_ball, x_ball, 0, 0);
    while (SCP_FRT_PLAYER < 11 && SCP_SCD_PLAYER < 11)
    {
        while(readMove() == 0);
        //if(scanf("%c", &cmd) == 1 && cmd == 'Y') {
            movePlayer();
            moveBall();
            generateFrame();
        //}
    }
    if(SCP_FRT_PLAYER == 1) {
        printf("FIRST PLAYER WON!\n");
    }
    else {
        printf("SECOND PLAYER WON!\n");
    }
}

int main() {
    char cmd;
    printf("PRESS Y TO START! U TO EXIT\n");
    printf("FIRST PLAYER: UP -A DOWN - Z\nSECOND PLAYER: UP - K DOWN - M\n");
    while(scanf("%c", &cmd) == 1) {
        if(cmd == 'Y') {
            scanf("%c", &cmd);
            startGame();
        }
        else if(cmd == 'U') {
            break;
        }
        printf("PRESS Y TO START! U TO EXIT\n");
    }
    printf("GG!\n");
    return 0;
}
