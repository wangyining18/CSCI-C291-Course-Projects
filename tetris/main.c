/*main.c --- 
 * 
 * Filename: main.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Thu Aug 18 16:32:20 2016
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2004-2007 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */
#include <stdio.h>
#include <ncurses.h>
#include "tetromino.h"
#include "highscore.h"
#include "game.h"

int main(int argc, char *argv[]) {
  int status = 1;
  highscore_t * highscores;
  if (argc!=2) { 
     printf("Please specify a high score file\n"); 
     return (-1); 
  }
  highscores = malloc(sizeof(highscore_t)); 
  highscores = game(highscores);
  
  int x, y;
  nodelay(stdscr,FALSE);
  clear();
  getmaxyx(stdscr,y,x);

  highscore_t *scorelist = load_scores(argv[1]);
 
  char initial[128];
  if(compare_highscore( scorelist, highscores->score, 10)){ 
     mvprintw(1,x/2-5,"  SCORES  ");
     mvprintw(2,x/2-5,"#############");
     mvprintw(8,x/2-5,"Enter your initials");		
     getstr(initial);
     mvprintw(10,x/2-5, "You Entered: %s",initial);
     mvprintw(16,x/2-5, "Hit c to continue");
     getch();
     clear();
  }

  mvprintw(1,x/2-5,"  SCORES  ");
  mvprintw(2,x/2-5,"#############");  
  if( compare_highscore( scorelist, highscores->score, 10) ){
    scorelist = insert_score(scorelist, initial, highscores->score) ;     
    store_scores(argv[1], scorelist);		
  }
 
  print_score_list (scorelist, x/2-5, 4, 10) ;

  mvprintw(16,x/2-5, "Hit e to end");
  getch();
  endwin();
  return (0);

  
}
/* main.c ends here */
