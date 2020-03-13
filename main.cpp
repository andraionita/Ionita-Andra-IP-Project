#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <graphics.h>
#include <cstring>
#include <thread>
using namespace std;
struct design_theme
{
    int BG_COLOR;
    int BORDER_COLOR;
    int MATRIX_THICKNESS;
    int MATRIXB_COLOR[11];
    int CONTAINER_THICKNESS;
    int PLAYER_COLOR;
    int NOTPLAYER_COLOR;
    int NRMAXPEBBLE;
    int NRMAXSOUNDS;
    char SOUNDS[11][51];
    char PEBBLE_LOC[11][51];
    char NOPEBBLE_LOC[11][51];
    char PEBBLE_HOV[11][51];
    char NUMBER[52][51];
    char SOUNDSIMG[11][51];
    char PLAYER1WIN[51];
    char PLAYER2WIN[51];
    char COMPUTERWIN[51];
    char PLAYERWIN[51];
    char COMPUTERPLATE[51];
    char PLAYERPLATE[51];
    char PLAYER1TURN[51];
    char PLAYER2TURN[51];
    char PLAYER1NOTURN[51];
    char PLAYER2NOTURN[51];
    char MENUBK[51];
    char OPTIONSBK[51];
    char THEMEIMG[51];
    char PLAYBT[51];
    char OPTIONSBT[51];
    char EXITBT[51];
    char PLAYBK[51];
    char BACK[51];
    char GAMESETBK[51];
    char GAMESETNOARR[51];
    char PLAYERBT[51];
    char COMPUTER[51];
    char ENEMY[51];
    char ENEMYBK[51];
    char COMP1[51];
    char COMP2[51];
    char COMP3[51];
    char ARRLE[51];
    char ARRRI[51];
    char RESET[51];
    char SNDONOFF[2][51];
} THEME[3];
struct point
{
    unsigned int x;
    unsigned int y;
};
///GLOBAL VARIABLES//////////////////////////////////////////////////////////////////////////////
int currentTheme=0,currentPebble=0,currentSounds=0;
int n=4, enemyType=0,changedEnemy=0;//,player1score,player2score;
unsigned int vest,nord,lat;
bool player,SoundON,tabela[101][101];
int player1score=0, player2score=0;
DWORD Height=GetSystemMetrics(SM_CYSCREEN);
DWORD Width=GetSystemMetrics(SM_CXSCREEN);
POINT cursorPosition;
///SETTING THE TIMS/////////////////////////////////////////////////////////////////////////////////////////////
void initialyzeThemes()
{
    ///Mountain///
    THEME[0].BORDER_COLOR=LIGHTGRAY;
    THEME[0].CONTAINER_THICKNESS=3;
    THEME[0].MATRIX_THICKNESS=6;
    THEME[0].MATRIXB_COLOR[0]=LIGHTGRAY;
    THEME[0].MATRIXB_COLOR[1]=CYAN;
    THEME[0].MATRIXB_COLOR[2]=RED;
    THEME[0].MATRIXB_COLOR[3]=LIGHTBLUE;
    THEME[0].MATRIXB_COLOR[4]=BLACK;
    THEME[0].MATRIXB_COLOR[5]=LIGHTGREEN;
    THEME[0].MATRIXB_COLOR[6]=LIGHTRED;
    THEME[0].PLAYER_COLOR=BLACK;
    THEME[0].NOTPLAYER_COLOR=LIGHTGRAY;
    THEME[0].NRMAXPEBBLE=7;
    THEME[0].NRMAXSOUNDS=0;
    strcpy(THEME[0].SNDONOFF[0],"Images/WhiteBlack/SoundOn.bmp");
    strcpy(THEME[0].SNDONOFF[1],"Images/WhiteBlack/SoundOff.bmp");
    strcpy(THEME[0].SOUNDS[0],"Sounds/WhiteBlack/DiggyHole.wav");
    strcpy(THEME[0].SOUNDS[1],"Sounds/WhiteBlack/FlintStone.wav");
    strcpy(THEME[0].SOUNDS[2],"Sounds/WhiteBlack/MKing.wav");
    strcpy(THEME[0].NUMBER[0],"Images/WhiteBlack/0.bmp");
    strcpy(THEME[0].NUMBER[1],"Images/WhiteBlack/1.bmp");
    strcpy(THEME[0].NUMBER[2],"Images/WhiteBlack/2.bmp");
    strcpy(THEME[0].NUMBER[3],"Images/WhiteBlack/3.bmp");
    strcpy(THEME[0].NUMBER[4],"Images/WhiteBlack/4.bmp");
    strcpy(THEME[0].NUMBER[5],"Images/WhiteBlack/5.bmp");
    strcpy(THEME[0].NUMBER[6],"Images/WhiteBlack/6.bmp");
    strcpy(THEME[0].NUMBER[7],"Images/WhiteBlack/7.bmp");
    strcpy(THEME[0].NUMBER[8],"Images/WhiteBlack/8.bmp");
    strcpy(THEME[0].NUMBER[9],"Images/WhiteBlack/9.bmp");
    strcpy(THEME[0].NUMBER[10],"Images/WhiteBlack/10.bmp");
    strcpy(THEME[0].NUMBER[11],"Images/WhiteBlack/11.bmp");
    strcpy(THEME[0].NUMBER[12],"Images/WhiteBlack/12.bmp");
    strcpy(THEME[0].NUMBER[13],"Images/WhiteBlack/13.bmp");
    strcpy(THEME[0].NUMBER[14],"Images/WhiteBlack/14.bmp");
    strcpy(THEME[0].NUMBER[15],"Images/WhiteBlack/15.bmp");
    strcpy(THEME[0].NUMBER[16],"Images/WhiteBlack/16.bmp");
    strcpy(THEME[0].NUMBER[17],"Images/WhiteBlack/17.bmp");
    strcpy(THEME[0].NUMBER[18],"Images/WhiteBlack/18.bmp");
    strcpy(THEME[0].NUMBER[19],"Images/WhiteBlack/19.bmp");
    strcpy(THEME[0].NUMBER[20],"Images/WhiteBlack/20.bmp");
    strcpy(THEME[0].NUMBER[21],"Images/WhiteBlack/21.bmp");
    strcpy(THEME[0].NUMBER[22],"Images/WhiteBlack/22.bmp");
    strcpy(THEME[0].NUMBER[23],"Images/WhiteBlack/23.bmp");
    strcpy(THEME[0].NUMBER[24],"Images/WhiteBlack/24.bmp");
    strcpy(THEME[0].NUMBER[25],"Images/WhiteBlack/25.bmp");
    strcpy(THEME[0].NUMBER[26],"Images/WhiteBlack/26.bmp");
    strcpy(THEME[0].NUMBER[27],"Images/WhiteBlack/27.bmp");
    strcpy(THEME[0].NUMBER[28],"Images/WhiteBlack/28.bmp");
    strcpy(THEME[0].NUMBER[29],"Images/WhiteBlack/29.bmp");
    strcpy(THEME[0].NUMBER[30],"Images/WhiteBlack/30.bmp");
    strcpy(THEME[0].NUMBER[31],"Images/WhiteBlack/31.bmp");
    strcpy(THEME[0].NUMBER[32],"Images/WhiteBlack/32.bmp");
    strcpy(THEME[0].NUMBER[33],"Images/WhiteBlack/33.bmp");
    strcpy(THEME[0].NUMBER[34],"Images/WhiteBlack/34.bmp");
    strcpy(THEME[0].NUMBER[35],"Images/WhiteBlack/35.bmp");
    strcpy(THEME[0].NUMBER[36],"Images/WhiteBlack/36.bmp");
    strcpy(THEME[0].NUMBER[37],"Images/WhiteBlack/37.bmp");
    strcpy(THEME[0].NUMBER[38],"Images/WhiteBlack/38.bmp");
    strcpy(THEME[0].NUMBER[39],"Images/WhiteBlack/39.bmp");
    strcpy(THEME[0].NUMBER[40],"Images/WhiteBlack/40.bmp");
    strcpy(THEME[0].NUMBER[41],"Images/WhiteBlack/41.bmp");
    strcpy(THEME[0].NUMBER[42],"Images/WhiteBlack/42.bmp");
    strcpy(THEME[0].NUMBER[43],"Images/WhiteBlack/43.bmp");
    strcpy(THEME[0].NUMBER[44],"Images/WhiteBlack/44.bmp");
    strcpy(THEME[0].NUMBER[45],"Images/WhiteBlack/45.bmp");
    strcpy(THEME[0].NUMBER[46],"Images/WhiteBlack/46.bmp");
    strcpy(THEME[0].NUMBER[47],"Images/WhiteBlack/47.bmp");
    strcpy(THEME[0].NUMBER[48],"Images/WhiteBlack/48.bmp");
    strcpy(THEME[0].NUMBER[49],"Images/WhiteBlack/49.bmp");
    strcpy(THEME[0].NUMBER[50],"Images/WhiteBlack/50.bmp");
    strcpy(THEME[0].PEBBLE_LOC[0],"Images/WhiteBlack/pebble0.bmp");
    strcpy(THEME[0].PEBBLE_LOC[1],"Images/WhiteBlack/Pebble1.bmp");
    strcpy(THEME[0].PEBBLE_LOC[2],"Images/WhiteBlack/Pebble2.bmp");
    strcpy(THEME[0].PEBBLE_LOC[3],"Images/WhiteBlack/Pebble3.bmp");
    strcpy(THEME[0].PEBBLE_LOC[4],"Images/WhiteBlack/Pebble4.bmp");
    strcpy(THEME[0].PEBBLE_LOC[5],"Images/WhiteBlack/Pebble5.bmp");
    strcpy(THEME[0].PEBBLE_LOC[6],"Images/WhiteBlack/Pebble6.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[0],"Images/WhiteBlack/nopebble0.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[1],"Images/WhiteBlack/nopebble1.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[2],"Images/WhiteBlack/nopebble2.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[3],"Images/WhiteBlack/nopebble3.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[4],"Images/WhiteBlack/nopebble4.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[5],"Images/WhiteBlack/nopebble5.bmp");
    strcpy(THEME[0].NOPEBBLE_LOC[6],"Images/WhiteBlack/nopebble6.bmp");
    strcpy(THEME[0].SOUNDSIMG[0],"Images/WhiteBlack/DiggyHole.bmp");
    strcpy(THEME[0].SOUNDSIMG[1],"Images/WhiteBlack/Flintstones.bmp");
    strcpy(THEME[0].SOUNDSIMG[2],"Images/WhiteBlack/MKing.bmp");
    strcpy(THEME[0].PEBBLE_HOV[0],"Images/WhiteBlack/HPebble0.bmp");
    strcpy(THEME[0].PLAYER1WIN,"Images/WhiteBlack/player1win.bmp");
    strcpy(THEME[0].PLAYER2WIN,"Images/WhiteBlack/player2win.bmp");
    strcpy(THEME[0].COMPUTERWIN,"Images/WhiteBlack/computerwin.bmp");
    strcpy(THEME[0].PLAYERWIN,"Images/WhiteBlack/playerwin.bmp");
    strcpy(THEME[0].PLAYERPLATE,"Images/WhiteBlack/playerplate.bmp");///*****
    strcpy(THEME[0].COMPUTERPLATE,"Images/WhiteBlack/computerplate.bmp");///*****
    strcpy(THEME[0].PLAYER1TURN,"Images/WhiteBlack/player1.bmp");
    strcpy(THEME[0].PLAYER2TURN,"Images/WhiteBlack/player2.bmp");
    strcpy(THEME[0].PLAYER1NOTURN,"Images/WhiteBlack/player1.2.bmp");
    strcpy(THEME[0].PLAYER2NOTURN,"Images/WhiteBlack/player2.2.bmp");
    strcpy(THEME[0].GAMESETNOARR,"Images/WhiteBlack/GameSettingsBackground1.bmp");
    strcpy(THEME[0].MENUBK,"Images/WhiteBlack/MenuBackground.bmp");
    strcpy(THEME[0].PLAYBT,"Images/WhiteBlack/Play.bmp");
    strcpy(THEME[0].OPTIONSBT,"Images/WhiteBlack/Options.bmp");
    strcpy(THEME[0].EXITBT,"Images/WhiteBlack/Exit.bmp");
    strcpy(THEME[0].PLAYBK,"Images/WhiteBlack/PlayBackground.bmp");
    strcpy(THEME[0].BACK,"Images/WhiteBlack/Back.bmp");
    strcpy(THEME[0].GAMESETBK,"Images/WhiteBlack/GameSettingsBackground.bmp");
    strcpy(THEME[0].PLAYERBT,"Images/WhiteBlack/Player.bmp");
    strcpy(THEME[0].COMPUTER,"Images/WhiteBlack/Computer.bmp");
    strcpy(THEME[0].ENEMY, "Images/WhiteBlack/Enemy.bmp");
    strcpy(THEME[0].ENEMYBK, "Images/WhiteBlack/EnemyBackground.bmp");
    strcpy(THEME[0].COMP1,"Images/WhiteBlack/ComputerEasy.bmp");
    strcpy(THEME[0].COMP2,"Images/WhiteBlack/ComputerMedium.bmp");
    strcpy(THEME[0].COMP3,"Images/WhiteBlack/ComputerHard.bmp");
    strcpy(THEME[0].ARRLE,"Images/WhiteBlack/arrowleft.bmp");
    strcpy(THEME[0].ARRRI,"Images/WhiteBlack/arrowright.bmp");
    strcpy(THEME[0].RESET,"Images/WhiteBlack/reset.bmp");
    strcpy(THEME[0].PEBBLE_HOV[0],"Images/WhiteBlack/HPebble0.bmp");
    strcpy(THEME[0].PEBBLE_HOV[1],"Images/WhiteBlack/HPebble1.bmp");
    strcpy(THEME[0].PEBBLE_HOV[2],"Images/WhiteBlack/HPebble2.bmp");
    strcpy(THEME[0].PEBBLE_HOV[3],"Images/WhiteBlack/HPebble3.bmp");
    strcpy(THEME[0].PEBBLE_HOV[4],"Images/WhiteBlack/HPebble4.bmp");
    strcpy(THEME[0].PEBBLE_HOV[5],"Images/WhiteBlack/HPebble5.bmp");
    strcpy(THEME[0].PEBBLE_HOV[6],"Images/WhiteBlack/HPebble6.bmp");
    strcpy(THEME[0].OPTIONSBK,"Images/WhiteBlack/OptionsBackground.bmp");
    strcpy(THEME[0].THEMEIMG,"Images/WhiteBlack/themeimage.bmp");
    ///Mario///
    THEME[1].BORDER_COLOR=BLACK;
    THEME[1].CONTAINER_THICKNESS=3;
    THEME[1].MATRIX_THICKNESS=6;
    THEME[1].MATRIXB_COLOR[0]=BLACK;
    THEME[1].MATRIXB_COLOR[1]=RED;
    THEME[1].MATRIXB_COLOR[2]=GREEN;
    THEME[1].MATRIXB_COLOR[3]=LIGHTRED;
    THEME[1].MATRIXB_COLOR[4]=BLACK;
    THEME[1].MATRIXB_COLOR[5]=LIGHTGREEN;
    THEME[1].MATRIXB_COLOR[6]=LIGHTRED;
    THEME[1].PLAYER_COLOR=BLACK;
    THEME[1].NOTPLAYER_COLOR=LIGHTGRAY;
    THEME[1].NRMAXPEBBLE=4;
    THEME[1].NRMAXSOUNDS=0;
    strcpy(THEME[1].SNDONOFF[0],"Images/SuperMario/SoundOn.bmp");
    strcpy(THEME[1].SNDONOFF[1],"Images/SuperMario/SoundOff.bmp");
    strcpy(THEME[1].SOUNDS[0],"Sounds/SuperMario/OriginalTheme.wav");
    strcpy(THEME[1].SOUNDS[1],"Sounds/SuperMario/OverworldTheme.wav");
    strcpy(THEME[1].SOUNDS[2],"Sounds/SuperMario/GhostHouse.wav");
    strcpy(THEME[1].NUMBER[0],"Images/SuperMario/0.bmp");
    strcpy(THEME[1].NUMBER[1],"Images/SuperMario/1.bmp");
    strcpy(THEME[1].NUMBER[2],"Images/SuperMario/2.bmp");
    strcpy(THEME[1].NUMBER[3],"Images/SuperMario/3.bmp");
    strcpy(THEME[1].NUMBER[4],"Images/SuperMario/4.bmp");
    strcpy(THEME[1].NUMBER[5],"Images/SuperMario/5.bmp");
    strcpy(THEME[1].NUMBER[6],"Images/SuperMario/6.bmp");
    strcpy(THEME[1].NUMBER[7],"Images/SuperMario/7.bmp");
    strcpy(THEME[1].NUMBER[8],"Images/SuperMario/8.bmp");
    strcpy(THEME[1].NUMBER[9],"Images/SuperMario/9.bmp");
    strcpy(THEME[1].NUMBER[10],"Images/SuperMario/10.bmp");
    strcpy(THEME[1].NUMBER[11],"Images/SuperMario/11.bmp");
    strcpy(THEME[1].NUMBER[12],"Images/SuperMario/12.bmp");
    strcpy(THEME[1].NUMBER[13],"Images/SuperMario/13.bmp");
    strcpy(THEME[1].NUMBER[14],"Images/SuperMario/14.bmp");
    strcpy(THEME[1].NUMBER[15],"Images/SuperMario/15.bmp");
    strcpy(THEME[1].NUMBER[16],"Images/SuperMario/16.bmp");
    strcpy(THEME[1].NUMBER[17],"Images/SuperMario/17.bmp");
    strcpy(THEME[1].NUMBER[18],"Images/SuperMario/18.bmp");
    strcpy(THEME[1].NUMBER[19],"Images/SuperMario/19.bmp");
    strcpy(THEME[1].NUMBER[20],"Images/SuperMario/20.bmp");
    strcpy(THEME[1].NUMBER[21],"Images/SuperMario/21.bmp");
    strcpy(THEME[1].NUMBER[22],"Images/SuperMario/22.bmp");
    strcpy(THEME[1].NUMBER[23],"Images/SuperMario/23.bmp");
    strcpy(THEME[1].NUMBER[24],"Images/SuperMario/24.bmp");
    strcpy(THEME[1].NUMBER[25],"Images/SuperMario/25.bmp");
    strcpy(THEME[1].NUMBER[26],"Images/SuperMario/26.bmp");
    strcpy(THEME[1].NUMBER[27],"Images/SuperMario/27.bmp");
    strcpy(THEME[1].NUMBER[28],"Images/SuperMario/28.bmp");
    strcpy(THEME[1].NUMBER[29],"Images/SuperMario/29.bmp");
    strcpy(THEME[1].NUMBER[30],"Images/SuperMario/30.bmp");
    strcpy(THEME[1].NUMBER[31],"Images/SuperMario/31.bmp");
    strcpy(THEME[1].NUMBER[32],"Images/SuperMario/32.bmp");
    strcpy(THEME[1].NUMBER[33],"Images/SuperMario/33.bmp");
    strcpy(THEME[1].NUMBER[34],"Images/SuperMario/34.bmp");
    strcpy(THEME[1].NUMBER[35],"Images/SuperMario/35.bmp");
    strcpy(THEME[1].NUMBER[36],"Images/SuperMario/36.bmp");
    strcpy(THEME[1].NUMBER[37],"Images/SuperMario/37.bmp");
    strcpy(THEME[1].NUMBER[38],"Images/SuperMario/38.bmp");
    strcpy(THEME[1].NUMBER[39],"Images/SuperMario/39.bmp");
    strcpy(THEME[1].NUMBER[40],"Images/SuperMario/40.bmp");
    strcpy(THEME[1].NUMBER[41],"Images/SuperMario/41.bmp");
    strcpy(THEME[1].NUMBER[42],"Images/SuperMario/42.bmp");
    strcpy(THEME[1].NUMBER[43],"Images/SuperMario/43.bmp");
    strcpy(THEME[1].NUMBER[44],"Images/SuperMario/44.bmp");
    strcpy(THEME[1].NUMBER[45],"Images/SuperMario/45.bmp");
    strcpy(THEME[1].NUMBER[46],"Images/SuperMario/46.bmp");
    strcpy(THEME[1].NUMBER[47],"Images/SuperMario/47.bmp");
    strcpy(THEME[1].NUMBER[48],"Images/SuperMario/48.bmp");
    strcpy(THEME[1].NUMBER[49],"Images/SuperMario/49.bmp");
    strcpy(THEME[1].NUMBER[50],"Images/SuperMario/50.bmp");
    strcpy(THEME[1].PEBBLE_LOC[0],"Images/SuperMario/pebble0.bmp");
    strcpy(THEME[1].PEBBLE_LOC[1],"Images/SuperMario/Pebble1.bmp");
    strcpy(THEME[1].PEBBLE_LOC[2],"Images/SuperMario/Pebble2.bmp");
    strcpy(THEME[1].PEBBLE_LOC[3],"Images/SuperMario/Pebble3.bmp");
    strcpy(THEME[1].PEBBLE_LOC[4],"Images/SuperMario/Pebble4.bmp");
    strcpy(THEME[1].PEBBLE_LOC[5],"Images/SuperMario/Pebble5.bmp");
    strcpy(THEME[1].PEBBLE_LOC[6],"Images/SuperMario/Pebble6.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[0],"Images/SuperMario/nopebble0.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[1],"Images/SuperMario/nopebble1.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[2],"Images/SuperMario/nopebble2.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[3],"Images/SuperMario/nopebble3.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[4],"Images/SuperMario/nopebble4.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[5],"Images/SuperMario/nopebble5.bmp");
    strcpy(THEME[1].NOPEBBLE_LOC[6],"Images/SuperMario/nopebble6.bmp");
    strcpy(THEME[1].SOUNDSIMG[0],"Images/SuperMario/Otheme.bmp");
    strcpy(THEME[1].SOUNDSIMG[1],"Images/SuperMario/Overworld.bmp");
    strcpy(THEME[1].SOUNDSIMG[2],"Images/SuperMario/GhostHouse.bmp");
    strcpy(THEME[1].PEBBLE_HOV[0],"Images/SuperMario/HPebble0.bmp");
    strcpy(THEME[1].PLAYER1WIN,"Images/SuperMario/player1win.bmp");
    strcpy(THEME[1].PLAYER2WIN,"Images/SuperMario/player2win.bmp");
    strcpy(THEME[1].COMPUTERWIN,"Images/SuperMario/computerwin.bmp");
    strcpy(THEME[1].PLAYERWIN,"Images/SuperMario/playerwin.bmp");
    strcpy(THEME[1].PLAYERPLATE,"Images/SuperMario/playerplate.bmp");
    strcpy(THEME[1].COMPUTERPLATE,"Images/SuperMario/computerplate.bmp");
    strcpy(THEME[1].PLAYER1TURN,"Images/SuperMario/player1.bmp");
    strcpy(THEME[1].PLAYER2TURN,"Images/SuperMario/player2.bmp");
    strcpy(THEME[1].PLAYER1NOTURN,"Images/SuperMario/player1.2.bmp");
    strcpy(THEME[1].PLAYER2NOTURN,"Images/SuperMario/player2.2.bmp");
    strcpy(THEME[1].GAMESETNOARR,"Images/SuperMario/GameSettingsBackground1.bmp");
    strcpy(THEME[1].MENUBK,"Images/SuperMario/MenuBackground.bmp");
    strcpy(THEME[1].PLAYBT,"Images/SuperMario/Play.bmp");
    strcpy(THEME[1].OPTIONSBT,"Images/SuperMario/Options.bmp");
    strcpy(THEME[1].EXITBT,"Images/SuperMario/Exit.bmp");
    strcpy(THEME[1].PLAYBK,"Images/SuperMario/PlayBackground.bmp");
    strcpy(THEME[1].BACK,"Images/SuperMario/Back.bmp");
    strcpy(THEME[1].GAMESETBK,"Images/SuperMario/GameSettingsBackground.bmp");
    strcpy(THEME[1].PLAYERBT,"Images/SuperMario/Player.bmp");
    strcpy(THEME[1].COMPUTER,"Images/SuperMario/Computer.bmp");
    strcpy(THEME[1].ENEMY, "Images/SuperMario/Enemy.bmp");
    strcpy(THEME[1].ENEMYBK, "Images/SuperMario/EnemyBackground.bmp");
    strcpy(THEME[1].COMP1,"Images/SuperMario/ComputerEasy.bmp");
    strcpy(THEME[1].COMP2,"Images/SuperMario/ComputerMedium.bmp");
    strcpy(THEME[1].COMP3,"Images/SuperMario/ComputerHard.bmp");
    strcpy(THEME[1].ARRLE,"Images/SuperMario/arrowleft.bmp");
    strcpy(THEME[1].ARRRI,"Images/SuperMario/arrowright.bmp");
    strcpy(THEME[1].RESET,"Images/SuperMario/reset.bmp");
    strcpy(THEME[1].PEBBLE_HOV[0],"Images/SuperMario/HPebble0.bmp");
    strcpy(THEME[1].PEBBLE_HOV[1],"Images/SuperMario/HPebble1.bmp");
    strcpy(THEME[1].PEBBLE_HOV[2],"Images/SuperMario/HPebble2.bmp");
    strcpy(THEME[1].PEBBLE_HOV[3],"Images/SuperMario/HPebble3.bmp");
    strcpy(THEME[1].PEBBLE_HOV[4],"Images/SuperMario/HPebble4.bmp");
    strcpy(THEME[1].PEBBLE_HOV[5],"Images/SuperMario/HPebble5.bmp");
    strcpy(THEME[1].PEBBLE_HOV[6],"Images/SuperMario/HPebble6.bmp");
    strcpy(THEME[1].OPTIONSBK,"Images/SuperMario/OptionsBackground.bmp");
    strcpy(THEME[1].THEMEIMG,"Images/SuperMario/themeimage.bmp");
    ///Christmas///
    THEME[2].BORDER_COLOR=WHITE;
    THEME[2].CONTAINER_THICKNESS=3;
    THEME[2].MATRIX_THICKNESS=6;
    THEME[2].MATRIXB_COLOR[0]=GREEN;
    THEME[2].MATRIXB_COLOR[1]=WHITE;
    THEME[2].MATRIXB_COLOR[2]=YELLOW;
    THEME[2].MATRIXB_COLOR[3]=GREEN;
    THEME[2].MATRIXB_COLOR[4]=RED;
    THEME[2].PLAYER_COLOR=WHITE;
    THEME[2].NOTPLAYER_COLOR=LIGHTGRAY;
    THEME[2].NRMAXPEBBLE=5;
    THEME[2].NRMAXSOUNDS=0;
    strcpy(THEME[2].SNDONOFF[0],"Images/Christmas/SoundOn.bmp");
    strcpy(THEME[2].SNDONOFF[1],"Images/Christmas/SoundOff.bmp");
    strcpy(THEME[2].SOUNDS[0],"Sounds/Christmas/Nutcracker.wav");
    strcpy(THEME[2].SOUNDS[1],"Sounds/Christmas/Snow.wav");
    strcpy(THEME[2].SOUNDS[2],"Sounds/Christmas/Carol.wav");
    strcpy(THEME[2].NUMBER[0],"Images/Christmas/0.bmp");
    strcpy(THEME[2].NUMBER[1],"Images/Christmas/1.bmp");
    strcpy(THEME[2].NUMBER[2],"Images/Christmas/2.bmp");
    strcpy(THEME[2].NUMBER[3],"Images/Christmas/3.bmp");
    strcpy(THEME[2].NUMBER[4],"Images/Christmas/4.bmp");
    strcpy(THEME[2].NUMBER[5],"Images/Christmas/5.bmp");
    strcpy(THEME[2].NUMBER[6],"Images/Christmas/6.bmp");
    strcpy(THEME[2].NUMBER[7],"Images/Christmas/7.bmp");
    strcpy(THEME[2].NUMBER[8],"Images/Christmas/8.bmp");
    strcpy(THEME[2].NUMBER[9],"Images/Christmas/9.bmp");
    strcpy(THEME[2].NUMBER[10],"Images/Christmas/10.bmp");
    strcpy(THEME[2].NUMBER[11],"Images/Christmas/11.bmp");
    strcpy(THEME[2].NUMBER[12],"Images/Christmas/12.bmp");
    strcpy(THEME[2].NUMBER[13],"Images/Christmas/13.bmp");
    strcpy(THEME[2].NUMBER[14],"Images/Christmas/14.bmp");
    strcpy(THEME[2].NUMBER[15],"Images/Christmas/15.bmp");
    strcpy(THEME[2].NUMBER[16],"Images/Christmas/16.bmp");
    strcpy(THEME[2].NUMBER[17],"Images/Christmas/17.bmp");
    strcpy(THEME[2].NUMBER[18],"Images/Christmas/18.bmp");
    strcpy(THEME[2].NUMBER[19],"Images/Christmas/19.bmp");
    strcpy(THEME[2].NUMBER[20],"Images/Christmas/20.bmp");
    strcpy(THEME[2].NUMBER[21],"Images/Christmas/21.bmp");
    strcpy(THEME[2].NUMBER[22],"Images/Christmas/22.bmp");
    strcpy(THEME[2].NUMBER[23],"Images/Christmas/23.bmp");
    strcpy(THEME[2].NUMBER[24],"Images/Christmas/24.bmp");
    strcpy(THEME[2].NUMBER[25],"Images/Christmas/25.bmp");
    strcpy(THEME[2].NUMBER[26],"Images/Christmas/26.bmp");
    strcpy(THEME[2].NUMBER[27],"Images/Christmas/27.bmp");
    strcpy(THEME[2].NUMBER[28],"Images/Christmas/28.bmp");
    strcpy(THEME[2].NUMBER[29],"Images/Christmas/29.bmp");
    strcpy(THEME[2].NUMBER[30],"Images/Christmas/30.bmp");
    strcpy(THEME[2].NUMBER[31],"Images/Christmas/31.bmp");
    strcpy(THEME[2].NUMBER[32],"Images/Christmas/32.bmp");
    strcpy(THEME[2].NUMBER[33],"Images/Christmas/33.bmp");
    strcpy(THEME[2].NUMBER[34],"Images/Christmas/34.bmp");
    strcpy(THEME[2].NUMBER[35],"Images/Christmas/35.bmp");
    strcpy(THEME[2].NUMBER[36],"Images/Christmas/36.bmp");
    strcpy(THEME[2].NUMBER[37],"Images/Christmas/37.bmp");
    strcpy(THEME[2].NUMBER[38],"Images/Christmas/38.bmp");
    strcpy(THEME[2].NUMBER[39],"Images/Christmas/39.bmp");
    strcpy(THEME[2].NUMBER[40],"Images/Christmas/40.bmp");
    strcpy(THEME[2].NUMBER[41],"Images/Christmas/41.bmp");
    strcpy(THEME[2].NUMBER[42],"Images/Christmas/42.bmp");
    strcpy(THEME[2].NUMBER[43],"Images/Christmas/43.bmp");
    strcpy(THEME[2].NUMBER[44],"Images/Christmas/44.bmp");
    strcpy(THEME[2].NUMBER[45],"Images/Christmas/45.bmp");
    strcpy(THEME[2].NUMBER[46],"Images/Christmas/46.bmp");
    strcpy(THEME[2].NUMBER[47],"Images/Christmas/47.bmp");
    strcpy(THEME[2].NUMBER[48],"Images/Christmas/48.bmp");
    strcpy(THEME[2].NUMBER[49],"Images/Christmas/49.bmp");
    strcpy(THEME[2].NUMBER[50],"Images/Christmas/50.bmp");
    strcpy(THEME[2].PEBBLE_LOC[0],"Images/Christmas/pebble0.bmp");
    strcpy(THEME[2].PEBBLE_LOC[1],"Images/Christmas/Pebble1.bmp");
    strcpy(THEME[2].PEBBLE_LOC[2],"Images/Christmas/Pebble2.bmp");
    strcpy(THEME[2].PEBBLE_LOC[3],"Images/Christmas/Pebble3.bmp");
    strcpy(THEME[2].PEBBLE_LOC[4],"Images/Christmas/Pebble4.bmp");
    strcpy(THEME[2].NOPEBBLE_LOC[0],"Images/Christmas/nopebble0.bmp");
    strcpy(THEME[2].NOPEBBLE_LOC[1],"Images/Christmas/nopebble1.bmp");
    strcpy(THEME[2].NOPEBBLE_LOC[2],"Images/Christmas/nopebble2.bmp");
    strcpy(THEME[2].NOPEBBLE_LOC[3],"Images/Christmas/nopebble3.bmp");
    strcpy(THEME[2].NOPEBBLE_LOC[4],"Images/Christmas/nopebble4.bmp");
    strcpy(THEME[2].SOUNDSIMG[0],"Images/Christmas/NutCracker.bmp");
    strcpy(THEME[2].SOUNDSIMG[1],"Images/Christmas/Snow.bmp");
    strcpy(THEME[2].SOUNDSIMG[2],"Images/Christmas/Carol.bmp");
    strcpy(THEME[2].PEBBLE_HOV[0],"Images/Christmas/HPebble0.bmp");
    strcpy(THEME[2].PLAYER1WIN,"Images/Christmas/player1win.bmp");
    strcpy(THEME[2].PLAYER2WIN,"Images/Christmas/player2win.bmp");
    strcpy(THEME[2].COMPUTERWIN,"Images/Christmas/computerwin.bmp");
    strcpy(THEME[2].PLAYERWIN,"Images/Christmas/playerwin.bmp");
    strcpy(THEME[2].PLAYERPLATE,"Images/Christmas/playerplate.bmp");///*****
    strcpy(THEME[2].COMPUTERPLATE,"Images/Christmas/computerplate.bmp");///*****
    strcpy(THEME[2].PLAYER1TURN,"Images/Christmas/Player1.bmp");
    strcpy(THEME[2].PLAYER2TURN,"Images/Christmas/Player2.bmp");
    strcpy(THEME[2].PLAYER1NOTURN,"Images/Christmas/Player1.1.bmp");
    strcpy(THEME[2].PLAYER2NOTURN,"Images/Christmas/Player2.1.bmp");
    strcpy(THEME[2].GAMESETNOARR,"Images/Christmas/GameSettingsBackground1.bmp");
    strcpy(THEME[2].MENUBK,"Images/Christmas/MenuBackground.bmp");
    strcpy(THEME[2].PLAYBT,"Images/Christmas/Play.bmp");
    strcpy(THEME[2].OPTIONSBT,"Images/Christmas/Options.bmp");
    strcpy(THEME[2].EXITBT,"Images/Christmas/Exit.bmp");
    strcpy(THEME[2].PLAYBK,"Images/Christmas/PlayBackground.bmp");
    strcpy(THEME[2].BACK,"Images/Christmas/Back.bmp");
    strcpy(THEME[2].GAMESETBK,"Images/Christmas/GameSettingsBackground.bmp");
    strcpy(THEME[2].PLAYERBT,"Images/Christmas/Player.bmp");
    strcpy(THEME[2].COMPUTER,"Images/Christmas/Computer.bmp");
    strcpy(THEME[2].ENEMY, "Images/Christmas/Enemy.bmp");
    strcpy(THEME[2].ENEMYBK, "Images/Christmas/EnemyBackground.bmp");
    strcpy(THEME[2].COMP1,"Images/Christmas/ComputerEasy.bmp");
    strcpy(THEME[2].COMP2,"Images/Christmas/ComputerMedium.bmp");
    strcpy(THEME[2].COMP3,"Images/Christmas/ComputerHard.bmp");
    strcpy(THEME[2].ARRLE,"Images/Christmas/arrowleft.bmp");
    strcpy(THEME[2].ARRRI,"Images/Christmas/arrowright.bmp");
    strcpy(THEME[2].RESET,"Images/Christmas/Reset.bmp");
    strcpy(THEME[2].PEBBLE_HOV[0],"Images/Christmas/HPebble0.bmp");
    strcpy(THEME[2].PEBBLE_HOV[1],"Images/Christmas/HPebble1.bmp");
    strcpy(THEME[2].PEBBLE_HOV[2],"Images/Christmas/HPebble2.bmp");
    strcpy(THEME[2].PEBBLE_HOV[3],"Images/Christmas/HPebble3.bmp");
    strcpy(THEME[2].PEBBLE_HOV[4],"Images/Christmas/HPebble4.bmp");
    strcpy(THEME[2].OPTIONSBK,"Images/Christmas/OptionsBackground.bmp");
    strcpy(THEME[2].THEMEIMG,"Images/Christmas/themeimage.bmp");
}
void callSoundThread()
{
    PlaySound(THEME[currentTheme].SOUNDS[currentSounds],NULL,SND_LOOP | SND_ASYNC);
}
///.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawContainer(int x1,int y1,int x2,int y2)
{
    setcolor(THEME[currentTheme].BORDER_COLOR);
    for(int i=0; i<THEME[currentTheme].CONTAINER_THICKNESS; i++)
        rectangle(x1+i,y1+i,x2-i,y2-i);
}
///Matrix Graphic Functions
void drawMatrixCell(int x1,int y1,int x2,int y2)
{
    setcolor(THEME[currentTheme].MATRIXB_COLOR[currentPebble]);
    for(int i=0; i<THEME[currentTheme].MATRIX_THICKNESS; i++)
        rectangle(x1+i,y1+i,x2-i,y2-i);
}
void drawFrame(int x1,int y1,int x2,int y2,int t)
{
    for(int i=0; i<t; i++)
        rectangle(x1+i,y1+i,x2-i,y2-i);
}
void drawMatrixVLine(int x,int y,int L)
{
    setcolor(THEME[currentTheme].MATRIXB_COLOR[currentPebble]);
    for(int i=0; i<THEME[currentTheme].MATRIX_THICKNESS; i++)
        line(x+i,y,x+i,y+L);
}
void drawMatrixHLine(int x,int y,int L)
{
    setcolor(THEME[currentTheme].MATRIXB_COLOR[currentPebble]);
    for(int i=0; i<THEME[currentTheme].MATRIX_THICKNESS; i++)
        line(x,y+i,x+L,y+i);
}

///DRAWING THE TABLE
void initialyzeTable()
{
    int L=Height*8/10;
    lat=L/n;
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    vest=(Width-lat*n-t*n)*1/2;
    nord=(Height-lat*n-t*n)*1/2;
    drawMatrixCell(vest-t+1,nord-t+1,vest+lat*n+t*n-1,nord+lat*n+t*n-1);
    readimagefile(THEME[currentTheme].NOPEBBLE_LOC[currentPebble],vest+1,nord+1,vest+lat*n+t*(n-1)-1,nord+lat*n+t*(n-1)-1);
    for(int i=1; i<n; i++)
    {
        drawMatrixVLine(vest+lat*i+(i-1)*t,nord,lat*n+t*n-1);
        drawMatrixHLine(vest,nord+lat*i+(i-1)*t,lat*n+t*n-1);
    }
    for(int i=0; i<n/2; i++)
        for(int j=n/2; j<n; j++)
            readimagefile(THEME[currentTheme].PEBBLE_LOC[currentPebble],vest+lat*i+t*(i+1),nord+lat*j+t*(j+1),vest+lat*i+t*(i-1)+lat,nord+lat*j+t*(j-1)+lat);
}
void initialyzeMenu()
{
    readimagefile(THEME[currentTheme].MENUBK,0,0,Width,Height);
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    drawContainer(Width*8.5/20,Height*8/20,Width*11.5/20,Height*11/20);
    readimagefile(THEME[currentTheme].PLAYBT,Width*8.5/20+t,Height*8/20+t,Width*11.5/20-t,Height*11/20-t);
    drawContainer(Width*8/20,Height*11.5/20,Width*12/20,Height*14.5/20);
    readimagefile(THEME[currentTheme].OPTIONSBT,Width*8/20+t,Height*11.5/20+t,Width*12/20-t,Height*14.5/20-t);
    drawContainer(Width*9/20,Height*15/20,Width*11/20,Height*17/20);
    readimagefile(THEME[currentTheme].EXITBT,Width*9/20+t,Height*15/20+t,Width*11/20-t,Height*17/20-t);
    drawContainer(Width*1/20,Height*17/20,Width*1/20+Height*2/20,Height*19/20);
    readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
}
void initialyzeOptions()
{
    readimagefile(THEME[currentTheme].OPTIONSBK,0,0,Width,Height);
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    drawContainer(Width*17.5/20,Height*17.5/20,Width*19.5/20,Height*19.5/20);
    readimagefile(THEME[currentTheme].BACK,Width*17.5/20+t,Height*17.5/20+t,Width*19.5/20-t,Height*19.5/20-t);
    drawContainer(Width*7/20,Height*6/20,Width*13/20,Height*9.5/20);
    readimagefile(THEME[currentTheme].THEMEIMG,Width*7/20+t,Height*6/20+t,Width*13/20-t,Height*9.5/20-t);
    drawContainer(Width*6.5/20-Height*1.5/20,Height*7/20,Width*6.5/20,Height*8.5/20);
    readimagefile(THEME[currentTheme].ARRLE,Width*6.5/20-Height*1.5/20+t,Height*7/20+t,Width*6.5/20-t,Height*8.5/20-t);
    drawContainer(Width*13.5/20,Height*7/20,Width*13.5/20+Height*1.5/20,Height*8.5/20);
    readimagefile(THEME[currentTheme].ARRRI,Width*13.5/20+t,Height*7/20+t,Width*13.5/20+Height*1.5/20-t,Height*8.5/20-t);
    drawContainer(Width*7/20,Height*10.5/20,Width*13/20,Height*14/20);
    readimagefile(THEME[currentTheme].SOUNDSIMG[currentSounds],Width*7/20+t,Height*10.5/20+t,Width*13/20-t,Height*14/20-t);
    drawContainer(Width*6.5/20-Height*1.5/20,Height*11.5/20,Width*6.5/20,Height*13/20);
    readimagefile(THEME[currentTheme].ARRLE,Width*6.5/20-Height*1.5/20+t,Height*11.5/20+t,Width*6.5/20-t,Height*13/20-t);
    drawContainer(Width*13.5/20,Height*11.5/20,Width*13.5/20+Height*1.5/20,Height*13/20);
    readimagefile(THEME[currentTheme].ARRRI,Width*13.5/20+t,Height*11.5/20+t,Width*13.5/20+Height*1.5/20-t,Height*13/20-t);
    drawContainer(Width*1/20,Height*17/20,Width*1/20+Height*2/20,Height*19/20);
    readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
}
void procedureOptions()
{
    bool quitOptions=1;
    unsigned int x1,y1;
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    while(quitOptions)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursorPosition);
            x1=cursorPosition.x;
            y1=cursorPosition.y;
            if(x1>Width*17.5/20 && x1<Width*19.5/20 && y1>Height*17.5/20 && y1<Height*19.5/20)
                quitOptions=0;
            else if(x1>Width*6.5/20-Height*1.5/20 && x1<Width*6.5/20 && y1>Height*7/20 && y1<Height*8.5/20)
            {
                currentTheme--;
                if(currentTheme<0)
                    currentTheme=2;
                currentPebble=0;
                currentSounds=0;
                if(!SoundON)
                    callSoundThread();
                initialyzeOptions();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*13.5/20 && x1<Width*13.5/20+Height*1.5/20 && y1>Height*7/20 && y1<Height*8.5/20)
            {
                currentTheme++;
                if(currentTheme>2)
                    currentTheme=0;
                currentPebble=0;
                currentSounds=0;
                if(!SoundON)
                    callSoundThread();
                initialyzeOptions();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*6.5/20-Height*1.5/20 && x1<Width*6.5/20 && y1>Height*11.5/20 && y1<Height*13/20)
            {
                currentSounds--;
                if(currentSounds<0)
                    currentSounds=2;
                readimagefile(THEME[currentTheme].SOUNDSIMG[currentSounds],Width*7/20+t,Height*10.5/20+t,Width*13/20-t,Height*14/20-t);
                if(!SoundON)
                    callSoundThread();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*13.5/20 && x1<Width*13.5/20+Height*1.5/20 && y1>Height*11.5/20 && y1<Height*13/20)
            {
                currentSounds++;
                if(currentSounds>2)
                    currentSounds=0;
                readimagefile(THEME[currentTheme].SOUNDSIMG[currentSounds],Width*7/20+t,Height*10.5/20+t,Width*13/20-t,Height*14/20-t);
                if(!SoundON)
                    callSoundThread();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*1/20 && x1<Width*1/20+Height*2/20 && y1>Height*17/20 && y1<Height*19/20)
            {
                SoundON=1-SoundON;
                if(SoundON)
                    PlaySound(0,NULL,0);
                else
                    callSoundThread();
                readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
        }
    }
}
void initialyzePlay()
{

    readimagefile(THEME[currentTheme].PLAYBK,0,0,Width,Height);
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    drawContainer(Width*17.5/20,Height*17.5/20,Width*19.5/20,Height*19.5/20);
    readimagefile(THEME[currentTheme].BACK,Width*17.5/20+t,Height*17.5/20+t,Width*19.5/20-t,Height*19.5/20-t);
    drawContainer(Width*16.25/20,Height*7/20,Width*17.5/20,Height*9/20);
    drawContainer(Width*2.5/20,Height*7/20,Width*3.75/20,Height*9/20);
    readimagefile(THEME[currentTheme].NUMBER[player2score],Width*16.25/20+t,Height*7/20+t,Width*17.5/20-t,Height*9/20-t);
    readimagefile(THEME[currentTheme].NUMBER[player1score],Width*2.5/20+t,Height*7/20+t,Width*3.75/20-t,Height*9/20-t);
    drawContainer(Width*1/20,Height*17/20,Width*1/20+Height*2/20,Height*19/20);
    readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
    initialyzeTable();
}
void initialyzeMatrix()
{
    for(int i=n/2; i<n; i++)
        for(int j=0; j<n/2; j++)
            tabela[i][j]=1;
    for(int i=0; i<n/2; i++)
        for(int j=0; j<n; j++)
            tabela[i][j]=0;
    for(int i=n/2; i<n; i++)
        for(int j=n/2; j<n; j++)
            tabela[i][j]=0;
}
point getMatrixCoordinates(point P)
{
    unsigned int t=THEME[currentTheme].MATRIX_THICKNESS;
    P.x=P.x-vest;
    P.y=P.y-nord;
    P.x=P.x/(lat+t)+1;
    P.y=P.y/(lat+t)+1;
    unsigned int aux;
    aux=P.x;
    P.x=P.y-1;
    P.y=aux-1;
    return P;
}
void deletePebble(point P1)
{
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    readimagefile(THEME[currentTheme].NOPEBBLE_LOC[currentPebble],vest+lat*P1.y+t*(P1.y+1),nord+lat*P1.x+t*(P1.x+1),vest+lat*P1.y+t*(P1.y-1)+lat,nord+lat*P1.x+t*(P1.x-1)+lat);
}
void drawPebble(point P1)
{
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    readimagefile(THEME[currentTheme].PEBBLE_LOC[currentPebble],vest+lat*P1.y+t*(P1.y+1),nord+lat*P1.x+t*(P1.x+1),vest+lat*P1.y+t*(P1.y-1)+lat,nord+lat*P1.x+t*(P1.x-1)+lat);
}
bool gameIsFinished()
{
    if(player==0)
    {
        for(int i=n-1; i>=n/2; i--)
            for(int j=0; j<n/2; j++)
                if(tabela[i][j]==1 && tabela[i-1][j]==0)
                    return 0;
        for(int i=n/2; i<n; i++)
            for(int j=n/2; j<n; j++)
                if(tabela[i][j]==1 && tabela[i-1][j]==0)
                    return 0;
        for(int i=1; i<n/2; i++)
            for(int j=0; j<n/2; j++)
                if(tabela[i][j]==1 && tabela[i-1][j]==0)
                    return 0;
        for(int i=1; i<n/2; i++)
            for(int j=n/2; j<n; j++)
                if(tabela[i][j]==1 && tabela[i-1][j]==0)
                    return 0;
    }
    else
    {
        for(int i=n-1; i>=n/2; i--)
            for(int j=0; j<n/2; j++)
                if(tabela[i][j]==1 && tabela[i][j+1]==0)
                    return 0;
        for(int i=0; i<n/2; i++)
            for(int j=0; j<n/2; j++)
                if(tabela[i][j]==1 && tabela[i][j+1]==0)
                    return 0;
        for(int i=n/2; i<n; i++)
            for(int j=n/2; j<n-1; j++)
                if(tabela[i][j]==1 && tabela[i][j+1]==0)
                    return 0;
        for(int i=0; i<n/2; i++)
            for(int j=n/2; j<n-1; j++)
                if(tabela[i][j]==1 && tabela[i][j+1]==0)
                    return 0;
    }
    return 1;
}
void drawCurrentPlayer()
{
    int t=THEME[currentTheme].MATRIX_THICKNESS,t1=THEME[currentTheme].CONTAINER_THICKNESS;
    if(player==0)
    {
        setcolor(THEME[currentTheme].NOTPLAYER_COLOR);
        drawFrame(vest+lat*n+t*n+(vest-t)*1/10,nord+(lat*n+t*n)*0.5/10,vest+lat*n+t*n+(vest-t)*7/10,nord+(lat*n+t*n)*2/10,t1);
        readimagefile(THEME[currentTheme].PLAYER2NOTURN,vest+lat*n+t*n+(vest-t)*1/10+t1,nord+(lat*n+t*n)*0.5/10+t1,vest+lat*n+t*n+(vest-t)*7/10-t1,nord+(lat*n+t*n)*2/10-t1);
        setcolor(THEME[currentTheme].PLAYER_COLOR);
        drawFrame((vest-t)*3/10,nord+(lat*n+t*n)*0.5/10,(vest-t)*9/10,nord+(lat*n+t*n)*2/10,t1);
        readimagefile(THEME[currentTheme].PLAYER1TURN,(vest-t)*3/10+t1,nord+(lat*n+t*n)*0.5/10+t1,(vest-t)*9/10-t1,nord+(lat*n+t*n)*2/10-t1);
    }
    else
    {
        setcolor(THEME[currentTheme].NOTPLAYER_COLOR);
        drawFrame((vest-t)*3/10,nord+(lat*n+t*n)*0.5/10,(vest-t)*9/10,nord+(lat*n+t*n)*2/10,t1);
        readimagefile(THEME[currentTheme].PLAYER1NOTURN,(vest-t)*3/10+t1,nord+(lat*n+t*n)*0.5/10+t1,(vest-t)*9/10-t1,nord+(lat*n+t*n)*2/10-t1);
        setcolor(THEME[currentTheme].PLAYER_COLOR);
        drawFrame(vest+lat*n+t*n+(vest-t)*1/10,nord+(lat*n+t*n)*0.5/10,vest+lat*n+t*n+(vest-t)*7/10,nord+(lat*n+t*n)*2/10,t1);
        readimagefile(THEME[currentTheme].PLAYER2TURN,vest+lat*n+t*n+(vest-t)*1/10+t1,nord+(lat*n+t*n)*0.5/10+t1,vest+lat*n+t*n+(vest-t)*7/10-t1,nord+(lat*n+t*n)*2/10-t1);
    }
}
void drawComputerPlates()
{
    int t=THEME[currentTheme].MATRIX_THICKNESS,t1=THEME[currentTheme].CONTAINER_THICKNESS;
    setcolor(THEME[currentTheme].PLAYER_COLOR);
    drawFrame(vest+lat*n+t*n+(vest-t)*1/10,nord+(lat*n+t*n)*0.5/10,vest+lat*n+t*n+(vest-t)*7/10,nord+(lat*n+t*n)*2/10,t1);
    drawFrame((vest-t)*3/10,nord+(lat*n+t*n)*0.5/10,(vest-t)*9/10,nord+(lat*n+t*n)*2/10,t1);
    readimagefile(THEME[currentTheme].COMPUTERPLATE,vest+lat*n+t*n+(vest-t)*1/10+t1,nord+(lat*n+t*n)*0.5/10+t1,vest+lat*n+t*n+(vest-t)*7/10-t1,nord+(lat*n+t*n)*2/10-t1);
    readimagefile(THEME[currentTheme].PLAYERPLATE,(vest-t)*3/10+t1,nord+(lat*n+t*n)*0.5/10+t1,(vest-t)*9/10-t1,nord+(lat*n+t*n)*2/10-t1);
}
void procedurePebble(point P1)
{
    int i;
    bool oki=1;
    point P2;
    P2.x=P1.x;
    P2.y=P1.y;
    if(!tabela[P1.x][P1.y])
    {
        if(player==0)
        {
            i=P1.x;
            while(oki && i<n)
            {
                i++;
                if(tabela[i][P1.y])
                {
                    tabela[P1.x][P1.y]=1;
                    tabela[i][P1.y]=0;
                    P2.x=i;
                    drawPebble(P1);
                    deletePebble(P2);
                    oki=0;
                    player=1;
                }
            }
        }
        else
        {
            i=P1.y;
            while(oki && i>=0)
            {
                i--;
                if(tabela[P1.x][i])
                {
                    tabela[P1.x][P1.y]=1;
                    tabela[P1.x][i]=0;
                    P2.y=i;
                    drawPebble(P1);
                    deletePebble(P2);
                    oki=0;
                    player=0;
                }
            }
        }
    }
}
void drawHoverPebble(point P)
{
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    if(!tabela[P.x][P.y])
    {
        if(player==0)
        {
            for(int i=P.x; i<n; i++)
                if(tabela[i][P.y])
                {
                    readimagefile(THEME[currentTheme].PEBBLE_HOV[currentPebble],vest+lat*P.y+t*(P.y+1),nord+lat*i+t*(i+1),vest+lat*P.y+t*(P.y-1)+lat,nord+lat*i+t*(i-1)+lat);
                    readimagefile(THEME[currentTheme].PEBBLE_HOV[currentPebble],vest+lat*P.y+t*(P.y+1),nord+lat*P.x+t*(P.x+1),vest+lat*P.y+t*(P.y-1)+lat,nord+lat*P.x+t*(P.x-1)+lat);
                    i=n;
                }
        }
        else
        {
            for(int i=P.y; i>=0; i--)
                if(tabela[P.x][i])
                {
                    readimagefile(THEME[currentTheme].PEBBLE_HOV[currentPebble],vest+lat*P.y+t*(P.y+1),nord+lat*P.x+t*(P.x+1),vest+lat*P.y+t*(P.y-1)+lat,nord+lat*P.x+t*(P.x-1)+lat);
                    readimagefile(THEME[currentTheme].PEBBLE_HOV[currentPebble],vest+lat*i+t*(i+1),nord+lat*P.x+t*(P.x+1),vest+lat*i+t*(i-1)+lat,nord+lat*P.x+t*(P.x-1)+lat);
                    i=0;
                }
        }
    }
}
void deleteHoverPebble(point P, bool lp)
{
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    if(!tabela[P.x][P.y])
        readimagefile(THEME[currentTheme].NOPEBBLE_LOC[currentPebble],vest+lat*P.y+t*(P.y+1),nord+lat*P.x+t*(P.x+1),vest+lat*P.y+t*(P.y-1)+lat,nord+lat*P.x+t*(P.x-1)+lat);
    if(lp==0)
    {
        for(int i=P.x; i<n; i++)
            if(tabela[i][P.y])
            {
                P.x=i;
                drawPebble(P);
                i=n;
            }
    }
    else
    {
        for(int i=P.y; i>=0; i--)
            if(tabela[P.x][i])
            {
                P.y=i;
                drawPebble(P);
                i=0;
            }
    }

}
void computerEasy(bool &moved)
{
    point targetPosition;
    for(int i=0; i<n; i++)
        for(int j=n-2; j>=0; j--)
            if(tabela[i][j] && !tabela[i][j+1])
            {
                targetPosition.x=i;
                targetPosition.y=j;
                tabela[i][j]=0;
                deletePebble(targetPosition);
                targetPosition.y=j+1;
                drawPebble(targetPosition);
                tabela[i][j+1]=1;
                moved=1;
                i=n;
                j=0;
            }
}
void computerMedium(bool &moved)
{
    point targetPosition;
    int i, j;
    for( j=n-1; j>=0; j--)
        for( i=n-1; i>=0; i--)
            if(tabela[i][j]==1&&tabela[i][j+1]==0)
            {
                targetPosition.x=i;
                targetPosition.y=j;
                break;
            }

    if(targetPosition.y<n-2)
    {
        while(tabela[targetPosition.x][targetPosition.y+1]==1)
            targetPosition.y+=1;

        if(targetPosition.y<n-1&&tabela[targetPosition.x][targetPosition.y+1]==0)
        {
            tabela[targetPosition.x][targetPosition.y]=0;
            deletePebble(targetPosition);
            targetPosition.y+=2;
            if((targetPosition.y<=n-1||tabela[targetPosition.x][targetPosition.y]==1)&&tabela[targetPosition.x][targetPosition.y-1]==0)
                targetPosition.y-=1;

            if(targetPosition.y<n)
            {
                tabela[targetPosition.x][targetPosition.y]=1;
                drawPebble(targetPosition);

                moved=1;
            }
        }
    }
    else if(targetPosition.y==n-2&&tabela[targetPosition.x][targetPosition.y+1]==1)
    {

        for( i=n-1; i>=2; i--)
            for( j=n-1; j>=2; j--)
                if(tabela[i][j]==1)
                {
                    targetPosition.x=i;
                    targetPosition.y=j;
                    break;
                }
        if(targetPosition.y<n-1)
        {
            while(tabela[targetPosition.x][targetPosition.y+1]==1)
                targetPosition.y+=1;
        }
        if(targetPosition.y<n-2&&tabela[targetPosition.x][targetPosition.y+1]==0)
        {
            tabela[targetPosition.x][targetPosition.y]=0;
            deletePebble(targetPosition);
            targetPosition.y+=2;
            if((targetPosition.y>=n-1||tabela[targetPosition.x][targetPosition.y]==1)&&tabela[targetPosition.x][targetPosition.y-1]==0)
                targetPosition.y-=1;

            if(targetPosition.y<n)
            {
                tabela[targetPosition.x][targetPosition.y]=1;
                drawPebble(targetPosition);

                moved=1;
            }
        }


    }
    else if(targetPosition.y==n-2&&tabela[targetPosition.x][targetPosition.y+1]==0)

    {

        tabela[targetPosition.x][targetPosition.y]=0;
        deletePebble(targetPosition);
        targetPosition.y+=1;
        tabela[targetPosition.x][targetPosition.y]=1;
        drawPebble(targetPosition);
        moved=1;


    }
    else
    {

        for( i=n-1; i>=0; i--)
            for( j=n-1; j>=0; j--)
                if(tabela[i][j]==1)
                {
                    targetPosition.x=i;
                    targetPosition.y=j;
                    break;
                }
        if(targetPosition.y<n-2)
        {
            while(tabela[targetPosition.x][targetPosition.y+1]==1)
                targetPosition.y+=1;
        }
        if(targetPosition.y<n-1&&targetPosition.y!=n-1&&tabela[targetPosition.x][targetPosition.y+1]==0)
        {
            tabela[targetPosition.x][targetPosition.y]=0;
            deletePebble(targetPosition);
            targetPosition.y+=2;
            if((targetPosition.y>=n-1||tabela[targetPosition.x][targetPosition.y]==1)&&tabela[targetPosition.x][targetPosition.y-1]==0)
                targetPosition.y-=1;

            if(targetPosition.y<n)
            {
                tabela[targetPosition.x][targetPosition.y]=1;
                drawPebble(targetPosition);
                moved=1;
            }
        }
    }
}
bool hasBlockOnTop(int x,int y)
{
    for(int i=0; i<x; i++)
        if(!tabela[i][y])
            return 0;
    return 1;
}
bool hasBlockOnRight(int x,int y)
{
    for(int i=n-1; i>y; i--)
        if(!tabela[x][i])
            return 0;
    return 1;
}
bool isCritMove(int x,int y)///modify
{
    if(!hasBlockOnRight(x-1,y))
        return 0;
    if(!hasBlockOnTop(x-1,y))
        return 0;
    if(!hasBlockOnTop(x-1,y+1))
        return 0;
    return 1;
}
int pointsBellow(int x, int y)
{
    if(!hasBlockOnTop(x,y))
        return 0;
    int nr=0;
    while(tabela[x+1][y] && x<n)
    {
        nr++;
        x++;
    }
    return nr;
}
void advance(int i,int j)
{
    point targetPosition;
    targetPosition.x=i;
    targetPosition.y=j;
    tabela[i][j]=0;
    deletePebble(targetPosition);
    targetPosition.y=j+1;
    drawPebble(targetPosition);
    tabela[i][j+1]=1;
}
void computerHard(bool &moved)
{
    point targetPosition;
    targetPosition.x=0;
    for(int i=0; i<n-1; i++)
        if(tabela[0][i])
            for(int j=i+1; j<n; j++)
            {
                if(!tabela[0][j] && tabela[1][j] && ((pointsBellow(0,i)+(j-i))*1/2<=pointsBellow(0,j)))
                {
                    tabela[0][i]=0;
                    targetPosition.y=i;
                    deletePebble(targetPosition);
                    targetPosition.y=j;
                    tabela[0][j]=1;
                    drawPebble(targetPosition);
                    i=j=n;
                    moved=1;
                }
                else if(tabela[0][j])
                    j=n;
            }
    if(!moved)
    {
        for(int i=n-1; i>0; i--)
            for(int j=1; j<n; j++)
                if(!tabela[j][i] && tabela[j+1][i])
                {
                    for(int k=i-1; k>=0; k--)
                        if(tabela[j][k] && ((pointsBellow(j,k)+(i-k)<=pointsBellow(j,i))))
                        {
                            targetPosition.x=j;
                            targetPosition.y=k;
                            tabela[j][k]=0;
                            deletePebble(targetPosition);
                            tabela[j][i]=1;
                            targetPosition.y=i;
                            drawPebble(targetPosition);
                            moved=1;
                            j=n;
                            i=k=0;
                        }
                        else if(tabela[j][k])
                            k=0;
                    j=n;
                }
                else if(!tabela[j][i])
                    j=n;
    }
    if(!moved)
    {
        for(int i=1; i<n; i++)
            for(int j=0; j<n; j++)
                if(!tabela[j][i] && j!=0)
                {
                    for(int k=i-1 ; k>=0 ; k--)
                        if(tabela[j][k] && !hasBlockOnTop(j,k) && (i-k)<=j)
                        {
                            targetPosition.x=j;
                            targetPosition.y=k;
                            tabela[j][k]=0;
                            deletePebble(targetPosition);
                            targetPosition.y=i;
                            tabela[j][i]=1;
                            drawPebble(targetPosition);
                            moved=1;
                            i=j=n;
                            k=0;
                        }
                        else if(tabela[j][k])
                            k=0;
                    j=n;
                }
                else if(!tabela[j][i])
                    j=n;
    }
    if(!moved)
    {
        for(int i=1; i<n; i++)
            for(int j=0; j<n; j++)
                if(!tabela[j][i] && j!=0)
                {
                    for(int k=i-1 ; k>=0 ; k--)
                        if(tabela[j][k] && !tabela[j+1][k] && (i-k)<=j)
                        {
                            targetPosition.x=j;
                            targetPosition.y=k;
                            tabela[j][k]=0;
                            deletePebble(targetPosition);
                            targetPosition.y=i;
                            tabela[j][i]=1;
                            drawPebble(targetPosition);
                            moved=1;
                            i=j=n;
                            k=0;
                        }
                        else if(tabela[j][k])
                            k=0;
                    j=n;
                }
                else if(!tabela[j][i])
                    j=n;
    }
    if(!moved)
    {
        for(int i=1; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !isCritMove(i,j+1) && ((i!=n-1 && !tabela[i+1][j] && !tabela[i-1][j]) || (i==n-1 && !tabela[i-1][j])))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !isCritMove(i,j+1) && !hasBlockOnTop(i,j)  && ((i!=n-1 && !tabela[i+1][j])|| i==n-1))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !hasBlockOnTop(i,j) && ((i && tabela[i-1][j] && tabela[i-1][j+1]) || i==0))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !isCritMove(i,j+1) && ((i!=n-1 && !tabela[i+1][j])|| i==n-1))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && ((i && tabela[i-1][j] && tabela[i-1][j+1]) || i==0))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !isCritMove(i,j+1) && !hasBlockOnTop(i,j))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !isCritMove(i,j+1))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=1; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && ((i!=n-1 && !tabela[i+1][j] && !tabela[i-1][j]) || (i==n-1 && !tabela[i-1][j])))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && ((i!=n-1 && !tabela[i+1][j])|| i==n-1))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1] && !hasBlockOnTop(i,j))
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
    if(!moved)
    {
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(tabela[i][j] && !tabela[i][j+1])
                {
                    advance(i,j);
                    moved=1;
                    i=n;
                    j=0;
                }
    }
}
void computerTurn()
{
    if(!gameIsFinished())
    {
        bool moved=0;
        switch(enemyType)
        {
        case 1:
        {
            computerEasy(moved);
            break;
        }
        case 2:
        {
            computerMedium(moved);
            break;
        }
        case 3:
        {
            computerHard(moved);
            break;
        }
        }
        if(moved)
        {
            player=0;
            delay(500);
        }
    }
}
void procedurePlay(bool &outsideQuit,bool &backWasPressed)
{
    bool quitPlay=1,gameFinish=0,didHover=0,lastPlayer=0;
    int t=THEME[currentTheme].MATRIX_THICKNESS,t1=THEME[currentTheme].CONTAINER_THICKNESS;
    point P,P1,P2,P22;
    P22.x=0;
    P22.y=0;
    player=0;
    initialyzeMatrix();
    if(enemyType==0)
        drawCurrentPlayer();
    else
        drawComputerPlates();
    while(quitPlay)
    {
        GetCursorPos(&cursorPosition);
        P.x=cursorPosition.x;
        P.y=cursorPosition.y;
        if(P.x>vest && P.x<(vest+lat*n+t*(n-1)) && P.y>nord && P.y<(nord+lat*n+t*(n-1)) && !gameFinish)
        {
            P2=getMatrixCoordinates(P);
            if((P2.x!=P22.x || P2.y!=P22.y)|| !didHover)
            {
                deleteHoverPebble(P22,lastPlayer);
                drawHoverPebble(P2);
                didHover=1;
                P22=P2;
                lastPlayer=player;
            }
        }
        else if(didHover && !gameFinish)
        {
            deleteHoverPebble(P22,lastPlayer);
            didHover=0;
        }
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            P.x=cursorPosition.x;
            P.y=cursorPosition.y;
            if(P.x>Width*17.5/20 && P.x<Width*19.5/20 && P.y>Height*17.5/20 && P.y<Height*19.5/20)
            {
                quitPlay=0;
                backWasPressed=1;
                if(gameFinish)
                {
                    backWasPressed=0;
                    outsideQuit=0;
                }
            }
            else if(P.x>Width*1/20 && P.x<Width*1/20+Height*2/20 && P.y>Height*17/20 && P.y<Height*19/20)
            {
                SoundON=1-SoundON;
                if(SoundON)
                    PlaySound(0,NULL,0);
                else
                    callSoundThread();
                readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t1,Height*17/20+t1,Width*1/20+Height*2/20-t1,Height*19/20-t1);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if (P.x>Width*17.5/20 && P.x<Width*19.5/20 && P.y>Height*15/20 && P.y<Height*17/20 && gameFinish)
            {
                gameFinish=0;
                initialyzePlay();
                initialyzeMatrix();
                if(player==0)
                {
                    player2score++;
                    if(player2score>50)
                        player2score=0;
                    readimagefile(THEME[currentTheme].NUMBER[player2score],Width*16.25/20+t,Height*7/20+t,Width*17.5/20-t,Height*9/20-t);
                }
                else
                {
                    player1score++;
                    if(player1score>50)
                        player1score=0;
                    readimagefile(THEME[currentTheme].NUMBER[player1score],Width*2.5/20+t,Height*7/20+t,Width*3.75/20-t,Height*9/20-t);
                }
                if(enemyType==0)
                    drawCurrentPlayer();
                else
                    drawComputerPlates();
                player=0;
            }
            else if(P.x>vest && P.x<(vest+lat*n+t*(n-1)) && P.y>nord && P.y<(nord+lat*n+t*(n-1)))
            {
                P1=getMatrixCoordinates(P);
                procedurePebble(P1);
                if(enemyType==0)
                    drawCurrentPlayer();
                else if(player==1)
                    computerTurn();
                if(gameIsFinished())
                {
                    if(enemyType==0)
                    {
                        if(player==0)
                            readimagefile(THEME[currentTheme].PLAYER2WIN,vest-t,nord-t,vest+lat*n+t*n,nord+lat*n+t*n);
                        else
                            readimagefile(THEME[currentTheme].PLAYER1WIN,vest-t,nord-t,vest+lat*n+t*n,nord+lat*n+t*n);
                    }
                    else
                    {
                        if(player==0)
                            readimagefile(THEME[currentTheme].COMPUTERWIN,vest-t,nord-t,vest+lat*n+t*n,nord+lat*n+t*n);
                        else
                            readimagefile(THEME[currentTheme].PLAYERWIN,vest-t,nord-t,vest+lat*n+t*n,nord+lat*n+t*n);
                    }
                    drawContainer(Width*17.5/20,Height*15/20,Width*19.5/20,Height*17/20);
                    readimagefile(THEME[currentTheme].RESET,Width*17.5/20+t1,Height*15/20+t1,Width*19.5/20-t1,Height*17/20-t1);
                    gameFinish=1;
                }
                while(GetAsyncKeyState(VK_LBUTTON));
            }
        }
    }
}
///Game Settings MEnu///
void drawCurrentPebble()
{
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    drawMatrixCell(Width*8.8/20,Height*15.5/20,Width*11.2/20,Height*15.5/20+Width*2.4/20);
    readimagefile(THEME[currentTheme].PEBBLE_LOC[currentPebble],Width*8.8/20+t,Height*15.5/20+t,Width*11.2/20-t,Height*15.5/20+Width*2.4/20-t);
}
void initialyzeGameSettings()
{
    if(changedEnemy)
        readimagefile(THEME[currentTheme].GAMESETNOARR,0,0,Width,Height);
    else
        readimagefile(THEME[currentTheme].GAMESETBK,0,0,Width,Height);
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    drawContainer(Width*17.5/20,Height*17.5/20,Width*19.5/20,Height*19.5/20);
    readimagefile(THEME[currentTheme].BACK,Width*17.5/20+t,Height*17.5/20+t,Width*19.5/20-t,Height*19.5/20-t);
    switch(enemyType)
    {
    case 0:
    {
        drawContainer(Width*8.5/20,Height*8.5/20,Width*11.5/20,Height*11/20);
        readimagefile(THEME[currentTheme].PLAYERBT,Width*8.5/20+t,Height*8.5/20+t,Width*11.5/20-t,Height*11/20-t);
        break;
    }
    case 1:
    {
        drawContainer(Width*7/20,Height*8.5/20,Width*13/20,Height*11/20);
        readimagefile(THEME[currentTheme].COMP1,Width*7/20+t,Height*8.5/20+t,Width*13/20-t,Height*11/20-t);
        break;
    }
    case 2:
    {
        drawContainer(Width*6.5/20,Height*8.5/20,Width*13.5/20,Height*11/20);
        readimagefile(THEME[currentTheme].COMP2,Width*6.5/20+t,Height*8.5/20+t,Width*13.5/20-t,Height*11/20-t);
        break;
    }
    case 3:
    {
        drawContainer(Width*6.5/20,Height*8.5/20,Width*13.5/20,Height*11/20);
        readimagefile(THEME[currentTheme].COMP3,Width*6.5/20+t,Height*8.5/20+t,Width*13.5/20-t,Height*11/20-t);
        break;
    }
    }
    drawContainer(Width*8.5/20,Height*5.5/20,Width*11.5/20,Height*8/20);
    readimagefile(THEME[currentTheme].PLAYBT,Width*8.5/20+t,Height*5.5/20+t,Width*11.5/20-t,Height*8/20-t);
    drawContainer(Width*8.5/20,Height*5.5/20,Width*11.5/20,Height*8/20);
    drawContainer(Width*9.6/20,Height*12.75/20,Width*10.4/20,Height*12.75/20+Width*0.8/20);
    readimagefile(THEME[currentTheme].NUMBER[n],Width*9.6/20+t,Height*12.75/20+t,Width*10.4/20-t,Height*12.75/20+Width*0.8/20-t);
    drawContainer(Width*9/20,Height*12.75/20+Width*0.2/20,Width*9.4/20,Height*12.75/20+Width*0.6/20);
    readimagefile(THEME[currentTheme].ARRLE,Width*9/20+t,Height*12.75/20+Width*0.2/20+t,Width*9.4/20-t,Height*12.75/20+Width*0.6/20-t);
    drawContainer(Width*10.6/20,Height*12.75/20+Width*0.2/20,Width*11/20,Height*12.75/20+Width*0.6/20);
    readimagefile(THEME[currentTheme].ARRRI,Width*10.6/20+t,Height*12.75/20+Width*0.2/20+t,Width*11/20-t,Height*12.75/20+Width*0.6/20-t);
    drawContainer(Width*7.6/20,Height*15.5/20+Width*0.8/20,Width*8.3/20,Height*15.5/20+Width*1.5/20);
    readimagefile(THEME[currentTheme].ARRLE,Width*7.6/20+t,Height*15.5/20+Width*0.8/20+t,Width*8.3/20-t,Height*15.5/20+Width*1.5/20-t);
    drawContainer(Width*11.7/20,Height*15.5/20+Width*0.8/20,Width*12.4/20,Height*15.5/20+Width*1.5/20);
    readimagefile(THEME[currentTheme].ARRRI,Width*11.7/20+t,Height*15.5/20+Width*0.8/20+t,Width*12.4/20-t,Height*15.5/20+Width*1.5/20-t);
    drawCurrentPebble();
    drawContainer(Width*1/20,Height*17/20,Width*1/20+Height*2/20,Height*19/20);
    readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
}
void initialyzeEnemy()
{
    readimagefile(THEME[currentTheme].ENEMYBK,0,0,Width,Height);
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    drawContainer(Width*17.5/20,Height*17.5/20,Width*19.5/20,Height*19.5/20);
    readimagefile(THEME[currentTheme].BACK,Width*17.5/20+t,Height*17.5/20+t,Width*19.5/20-t,Height*19.5/20-t);
    drawContainer(Width*8.5/20,Height*5.5/20,Width*11.5/20,Height*8/20);
    readimagefile(THEME[currentTheme].PLAYERBT,Width*8.5/20+t,Height*5.5/20+t,Width*11.5/20-t,Height*8/20-t);
    drawContainer(Width*7/20,Height*8.5/20,Width*13/20,Height*11/20);
    readimagefile(THEME[currentTheme].COMP1,Width*7/20+t,Height*8.5/20+t,Width*13/20-t,Height*11/20-t);
    drawContainer(Width*6.5/20,Height*11.5/20,Width*13.5/20,Height*14/20);
    readimagefile(THEME[currentTheme].COMP2,Width*6.5/20+t,Height*11.5/20+t,Width*13.5/20-t,Height*14/20-t);
    drawContainer(Width*6.5/20,Height*14.5/20,Width*13.5/20,Height*17/20);
    readimagefile(THEME[currentTheme].COMP3,Width*6.5/20+t,Height*14.5/20+t,Width*13.5/20-t,Height*17/20-t);
    drawContainer(Width*1/20,Height*17/20,Width*1/20+Height*2/20,Height*19/20);
    readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
}
void procedureEnemy()
{
    bool quitEnemy=1;
    unsigned x1,y1;
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    while(quitEnemy)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursorPosition);
            x1=cursorPosition.x;
            y1=cursorPosition.y;
            if(x1>Width*17.5/20 && x1<Width*19.5/20 && y1>Height*17.5/20 && y1<Height*19.5/20)
                quitEnemy=0;
            else if(x1>Width*8.5/20 && x1<Width*11.5/20 && y1>Height*5.5/20 && y1<Height*8/20)
            {
                quitEnemy=0;
                enemyType=0;
            }
            else if(x1>Width*7/20 && x1<Width*13/20 && y1>Height*8.5/20 && y1<Height*11/20)
            {
                quitEnemy=0;
                enemyType=1;
            }
            else if(x1>Width*6.5/20 && x1<Width*13.5/20 && y1>Height*11.5/20 && y1<Height*14/20)
            {
                quitEnemy=0;
                enemyType=2;
            }
            else if(x1>Width*6.5/20 && x1<Width*13.5/20 && y1>Height*14.5/20 && y1<Height*17/20)
            {
                quitEnemy=0;
                enemyType=3;
            }
            else if(x1>Width*1/20 && x1<Width*1/20+Height*2/20 && y1>Height*17/20 && y1<Height*19/20)
            {
                SoundON=1-SoundON;
                if(SoundON)
                    PlaySound(0,NULL,0);
                else
                    callSoundThread();
                readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
        }
    }
}
void procedureGameSettings()
{
    bool quitGameSettings=1,backWasPressed=0;
    unsigned x1,y1;
    int t=THEME[currentTheme].MATRIX_THICKNESS;
    while(quitGameSettings)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursorPosition);
            x1=cursorPosition.x;
            y1=cursorPosition.y;
            if(x1>Width*17.5/20 && x1<Width*19.5/20 && y1>Height*17.5/20 && y1<Height*19.5/20)
                quitGameSettings=0;
            else if(x1>Width*8.5/20 && x1<Width*11.5/20 && y1>Height*5.5/20 && y1<Height*8/20)
            {
                player1score=player2score=0;
                initialyzePlay();
                while(GetAsyncKeyState(VK_LBUTTON));
                procedurePlay(quitGameSettings,backWasPressed);
                if(backWasPressed)
                {
                    initialyzeGameSettings();
                    while(GetAsyncKeyState(VK_LBUTTON));
                }
            }
            else if(x1>Width*7.75/20 && x1<Width*12.25/20 && y1>Height*8.5/20 && y1<Height*11/20)
            {
                changedEnemy=1;
                initialyzeEnemy();
                while(GetAsyncKeyState(VK_LBUTTON));
                procedureEnemy();
                while(GetAsyncKeyState(VK_LBUTTON));
                initialyzeGameSettings();
            }
            else if(x1>Width*7.6/20 && x1<Width*8.3/20 && y1>(Height*15.5/20+Width*0.8/20) && y1<(Height*15.5/20+Width*1.5/20))
            {
                currentPebble--;
                if(currentPebble==-1)
                    currentPebble=THEME[currentTheme].NRMAXPEBBLE-1;
                drawCurrentPebble();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*11.7/20 && x1<Width*12.4/20 && y1>(Height*15.5/20+Width*0.8/20) && y1<(Height*15.5/20+Width*1.5/20))
            {
                currentPebble++;
                if(currentPebble==THEME[currentTheme].NRMAXPEBBLE)
                    currentPebble=0;
                drawCurrentPebble();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*9/20 && x1<Width*9.4/20 && y1>(Height*12.75/20+Width*0.2/20) && y1<(Height*12.75/20+Width*0.6/20))
            {
                n-=2;
                if(n==0)
                    n=50;
                THEME[currentTheme].MATRIX_THICKNESS=6-n/10;
                readimagefile(THEME[currentTheme].NUMBER[n],Width*9.6/20+t,Height*12.75/20+t,Width*10.4/20-t,Height*12.75/20+Width*0.8/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*10.6/20 && x1<Width*11/20 && y1>(Height*12.75/20+Width*0.2/20) && y1<(Height*12.75/20+Width*0.6/20))
            {
                n+=2;
                if(n>50)
                    n=2;
                THEME[currentTheme].MATRIX_THICKNESS=6-n/10;
                readimagefile(THEME[currentTheme].NUMBER[n],Width*9.6/20+t,Height*12.75/20+t,Width*10.4/20-t,Height*12.75/20+Width*0.8/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*1/20 && x1<Width*1/20+Height*2/20 && y1>Height*17/20 && y1<Height*19/20)
            {
                SoundON=1-SoundON;
                if(SoundON)
                    PlaySound(0,NULL,0);
                else
                    callSoundThread();
                readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
        }
    }
}
///MAIN MENU-BACK////
void procedureMenu()
{
    bool quitGame=1;
    unsigned int x1,y1;
    int t=THEME[currentTheme].CONTAINER_THICKNESS;
    callSoundThread();
    while(quitGame)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursorPosition);
            x1=cursorPosition.x;
            y1=cursorPosition.y;
            if(x1>Width*9/20 && x1<Width*11/20 && y1>Height*15/20 && y1<Height*17/20)
            {
                quitGame=0;
            }
            else if(x1>Width*8/20 && x1<Width*12/20 && y1>Height*11.5/20 && y1<Height*14.5/20)
            {
                initialyzeOptions();
                while(GetAsyncKeyState(VK_LBUTTON));
                procedureOptions();
                initialyzeMenu();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*8.5/20 && x1<Width*11.5/20 && y1>Height*8/20 && y1<Height*11/20)
            {
                initialyzeGameSettings();
                while(GetAsyncKeyState(VK_LBUTTON));
                procedureGameSettings();
                initialyzeMenu();
                while(GetAsyncKeyState(VK_LBUTTON));
            }
            else if(x1>Width*1/20 && x1<Width*1/20+Height*2/20 && y1>Height*17/20 && y1<Height*19/20)
            {
                SoundON=1-SoundON;
                if(SoundON)
                    PlaySound(0,NULL,0);
                else
                    callSoundThread();
                readimagefile(THEME[currentTheme].SNDONOFF[SoundON],Width*1/20+t,Height*17/20+t,Width*1/20+Height*2/20-t,Height*19/20-t);
                while(GetAsyncKeyState(VK_LBUTTON));
            }
        }
    }
}
///MAIN FUNCTION
int main()
{
    initialyzeThemes();
    initwindow(Width,Height,"",-3,-3);
    initialyzeMenu();
    procedureMenu();
    closegraph();
    return 0;
}
