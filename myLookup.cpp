#include "myLookup.h"
#include <iostream>

bool LookUpTable2D::lookup(double y, double x, double *&o) {
    bool is_fault = false;  // Indicate if any clipping
    int ix_prev, ix_next, iy_prev, iy_next;

    // Test bounds and assign indices
    if (x >= col_scale.back()) {
        ix_prev = col_scale.size()-1;
        ix_next = col_scale.size()-1;
        is_fault = true;
    } else if (x <= col_scale.front()) {
        ix_prev = 0;
        ix_next = 0;
        is_fault = true;
    } else {
        vector<double>::iterator x_low = lower_bound(col_scale.begin(), col_scale.end(), x);
        ix_prev = x_low-col_scale.begin()-1;
        ix_next = ix_prev + 1;
    }

    if (y >= row_scale.back()) {
        iy_prev = row_scale.size()-1;
        iy_next = row_scale.size()-1;
        is_fault = true;
    } else if (y <= row_scale.front()) {
        iy_prev = 0;
        iy_next = 0;
        is_fault = true;
    } else {
        vector<double>::iterator y_low = lower_bound(row_scale.begin(), row_scale.end(), y);
        iy_prev = y_low-row_scale.begin()-1;
        iy_next = iy_prev + 1;
    }

    // Interpolation gradients
    double x_grad = 0;
    if (ix_next != ix_prev) {
        x_grad = (x-col_scale[ix_prev])/(col_scale[ix_next]-col_scale[ix_prev]);
    }

    double y_grad = 0;
    if (iy_next != iy_prev) {
        y_grad = (y-row_scale[iy_prev])/(row_scale[iy_next]-row_scale[iy_prev]);
    }

    // Interpolate
    double x_1 = table[iy_prev][ix_prev] + x_grad*(table[iy_prev][ix_next] - table[iy_prev][ix_prev]);
    double x_2 = table[iy_next][ix_prev] + x_grad*(table[iy_next][ix_next] - table[iy_next][ix_prev]);
    double y_res = x_1 + y_grad*(x_2 - x_1);
    *o = y_res;

    return is_fault;
}
