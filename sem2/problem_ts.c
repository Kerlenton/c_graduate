int double_area(struct triangle_t tr) {
    int area = 0;

    for (int i = 0; i < 3; i++) {
        area += ((unsigned long long)tr.pts[i % 3].x * 
                 (unsigned long long)tr.pts[(i + 1) % 3].y) - 
                ((unsigned long long)tr.pts[i % 3].y * 
                 (unsigned long long)tr.pts[(i + 1) % 3].x);
    }

    if (area > 0) {
        return area;
    } else {
        return -area;
    }
}
