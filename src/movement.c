#ifndef abs(x)
#define abs(x) (x > 0) ? x : -1 * x
#endif

int tax_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int next_move(int x1, int y1, int x2, int y2) {
    if (x1 > x2)
        return 0;
    else if (x1 < x2)
        return 2;
    else if (y1 < y2)
        return 1;
    return 3;
}

int fmd(char **matrix) {
    int rx, ry;
    int breaking = 0;
    int bx, by, bs = 0;
    //Getting the bot position
    for (int x = 0; x < 15; ++x) {
        for (int y = 0; y < 15; ++y) {
            if (matrix[x][y] == 'X') {
                rx = x;
                ry = y;
                breaking = 1;
            }
        }
        if (breaking) {
            break;
        }
    }
    //Getting the nearest garbage
    for (int x = 0; x < 15; ++x) {
        for (int y = 0; y < 15; ++y) {
            if (matrix[x][y] == 'o') {
                if (!bs || tax_distance(rx, ry, x, y) < bs) {
                    bs = tax_distance(rx, ry, x, y);
                    bx = x;
                    by = y;
                }
            }
        }
    }
    if (!bs) {
        bx = 6;
        by = 6;
    }
    //Making the next movement
    return next_move(rx, ry, bx, by);
}