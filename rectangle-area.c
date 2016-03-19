//
//  main.c
//  RectArea
//
//  Created by Joe Pak on 3/18/16.
//  Copyright © 2016 Joe Pak. All rights reserved.
//

#include <stdio.h>

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

int calculateArea(int length, int height)
{
    int area;
    area = length * height;
    
    return area;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int area;
    
    //sum areas of both rects
    area = calculateArea(C - A, D - B) + calculateArea(G - E, H - F);
    
    //find BL & TR coordinates for overlap
    int BL_x = MAX(A,E);
    int BL_y = MAX(B,F);
    int TR_x = MIN(C,G);
    int TR_y = MIN(D,H);
    
    //if rects overlap, subtract overlap area from sum of both rect areas
    if ((BL_x <= C && BL_x <= G) && (BL_y <= H || BL_y <= D) && (TR_x >= E && TR_x >= A) && (TR_y >= B && TR_y >= F))
    {
        area -= calculateArea(TR_x - BL_x, TR_y - BL_y);
    }

    return area;
}



int main(int argc, const char * argv[]) {
    
    printf("area: %d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));

    return 0;
}
