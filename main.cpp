#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef float fp_t;

//template<typename fp_t>
//diff_of_products() вычисляет a*b-c*d с максимальной ошибкой <= 1,5 единиц на послед месте
fp_t diff_of_products(fp_t a, fp_t b, fp_t c, fp_t d){

    fp_t w = d*c;
    fp_t e = std::fma(-d, c, w);
    fp_t f = std::fma(a, b, -w);

    return f+e;
}

//template<typename fp_t>
//вычисление действительных корней квадратного уравнения: ax^2 + bx + c = 0 при условии, что дискриминант b^2-4ac положителен
void solve_quadratic (std::vector<fp_t> coefficients, std::vector<fp_t> &roots){
    fp_t a, b, c;

    //Coefficients
    a = coefficients[0];
    b = coefficients[1];
    c = coefficients[2];

    cout<< endl<< "\tQuadratic equation:"<<endl<< "\t "<< a << "*x^2 + " <<b<< "*x + " << c << endl;

    fp_t diff_of = diff_of_products (b, b, 4.0*a, c);
    if (diff_of >= 0) {
        fp_t q = -0.5 * (b + copysign(std::sqrt(diff_of), b));
        roots[0] = q / a;
        roots[1] = c / q;
        cout << "\t\tRoots: " << endl;
        cout << "\t  x1 = " << roots[0] << "; x2 =  " << roots[1] << endl;
    }
    else
        cout<<"\tComplex roots :(..."<<endl;
}


int main(){
    vector<float> koef1 = {1, 1, -2};
    vector<float> koef2 = {1, 6, 9};
    vector<float> koef3 = {3, -8, -35};
    vector<float> koef4 = {1, 2, 2};
    vector<float> koef5 = {1, 2, 1};

    vector<float> r1(2);
    vector<float> r2(2);
    vector<float> r3(2);
    vector<float> r4(2);
    vector<float> r5(2);

    //2 different roots
    solve_quadratic(koef1, r1);

    //1 root of multiplicity 2
    solve_quadratic(koef2, r2);
    solve_quadratic(koef5, r5);

    //complex roots
    solve_quadratic(koef4, r4);

}