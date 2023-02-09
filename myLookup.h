#ifndef FPKICK_MYLOOKUP_H_
#define FPKICK_MYLOOKUP_H_

#include <vector>

using std::vector;

class LookUpTable2D {
    private:
        vector<vector<double>> table;
        vector<double> col_scale;
        vector<double> row_scale;

    public:
        LookUpTable2D(vector<vector<double>> mat, vector<double> rows, vector<double> cols){
            table = mat;
            row_scale = rows;
            col_scale = cols;
        };

        bool lookup(double iy, double ix, double *&o);
};

#endif  // FPKICK_MYLOOKUP_H_"
