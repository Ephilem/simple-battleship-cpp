#ifndef BIBLIOSTD_H
#define BIBLIOSTD_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stdexcept>

/*** CONSTANTES ***/
// Taille de la grille
#define TAILLE_GRILLE 11
// Paramètres réseau
#define MAXHOSTNAME 200
#define MAXCONNECTIONS 5
#define MAXRECV 500
#define PORTCOM 8000
#define MAXESSAIS 1000

/*** COULEUR LINUX ***/
#define STYLE_NORMAL "0"
#define STYLE_BOLD "1"
#define STYLE_ITALIC "3"
#define STYLE_UNDERLINE "4"

#define COLOR_BLACK "30"
#define COLOR_RED "31"
#define COLOR_GREEN "32"
#define COLOR_YELLOW "33"
#define COLOR_BLUE "34"
#define COLOR_MAGENTA "35"
#define COLOR_CYAN "36"
#define COLOR_WHITE "37"
#define COLOR_GRAY "90"
#define COLOR_BRIGHT_RED "91"
#define COLOR_BRIGHT_GREEN "92"
#define COLOR_BRIGHT_YELLOW "93"
#define COLOR_BRIGHT_BLUE "94"
#define COLOR_BRIGHT_MAGENTA "95"
#define COLOR_BRIGHT_CYAN "96"
#define COLOR_BRIGHT_WHITE "97"

#define BG_BLACK "40"
#define BG_RED "41"
#define BG_GREEN "42"
#define BG_YELLOW "43"
#define BG_BLUE "44"
#define BG_MAGENTA "45"
#define BG_CYAN "46"
#define BG_WHITE "47"
#define BG_BRIGHT_BLACK "100"
#define BG_BRIGHT_RED "101"
#define BG_BRIGHT_GREEN "102"
#define BG_BRIGHT_YELLOW "103"
#define BG_BRIGHT_BLUE "104"
#define BG_BRIGHT_MAGENTA "105"
#define BG_BRIGHT_CYAN "106"
#define BG_BRIGHT_WHITE "107"

#define COLORED_TEXT(msg, color) "\033[" << color << "m" << msg << "\033[0m"
#define COLORED_BG_TEXT(msg, color, bg) "\033[" << color << ";" << bg << "m" << msg << "\033[0m"
#define STYLED_TEXT(msg, style, color) "\033[" << style << ";" << color << "m" << msg << "\033[0m"
#define STYLED_BG_TEXT(msg, style, color, bg) "\033[" << style << ";" << color << ";" << bg << "m" << msg << "\033[0m"


using namespace std;

#endif
