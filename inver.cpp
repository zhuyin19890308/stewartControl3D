

#include <inver.h>
#include <cmath>


float r_up = 442.89;
float r_down = 760;
float h_zero = 618.3;
float h_mid = 768.3;
float s_up_jiaodian = 101;
float s_down_jiaodian = 250;


float leg[6];


void inver(float alpha1, float beta1, float gama1, float x1, float b_y1, float z1)
{
    float alpha;
    float beta;
    float B[24];
    float T_tmp;
    float b_T_tmp;
    float c_T_tmp;
    float d_T_tmp;
    float e_T_tmp;
    float f_T_tmp[16];
    float b_r_up[24];
    int i;
    int B_tmp_tmp;
    float C[24];

    //  运动平台基本参数设定
    // r_up=442.89;   %上虎克铰中心分布圆半径
    // r_down=760;    %下虎克铰中心分布圆半径
    // h_zero=618.3;  %平台零位时，上下虎克铰高度差
    // h_mid=768.3;   %平台中位时，上下虎克铰高度差
    // leg0=937.9;    %平台中位时，缸的伸长量
    // 上虎克铰到上平台下表面的距离
    // s_up_jiaodian=101;    %上虎克铰中心短边距离
    // s_down_jiaodian=250;  %下虎克铰中心短边距离
    alpha = std::asin(s_up_jiaodian * 0.5F / r_up);
    beta = std::asin(s_down_jiaodian * 0.5F / r_down);

    //  坐标变换
    // 上铰点坐标
    // 下铰点坐标
    B[0] = r_down * std::sin(1.04719758F - beta);
    B[4] = r_down * std::sin(beta + -1.04719758F);
    B[8] = r_down * std::sin(-1.04719758F - beta);
    B[12] = r_down * std::sin(beta + 3.14159274F);
    B[16] = r_down * std::sin(3.14159274F - beta);
    B[20] = r_down * std::sin(beta + 1.04719758F);
    B[1] = r_down * std::cos(1.04719758F - beta);
    B[5] = r_down * std::cos(beta + -1.04719758F);
    B[9] = r_down * std::cos(-1.04719758F - beta);
    B[13] = r_down * std::cos(beta + 3.14159274F);
    B[17] = r_down * std::cos(3.14159274F - beta);
    B[21] = r_down * std::cos(beta + 1.04719758F);

    // 动坐标系到静坐标系的齐次变换矩阵
    beta = std::cos(gama1);
    T_tmp = std::sin(alpha1);
    b_T_tmp = std::sin(gama1);
    c_T_tmp = std::cos(alpha1);
    d_T_tmp = std::sin(beta1);
    e_T_tmp = std::cos(beta1);
    f_T_tmp[0] = e_T_tmp * beta;
    f_T_tmp[4] = -c_T_tmp * b_T_tmp + T_tmp * d_T_tmp * beta;
    f_T_tmp[8] = T_tmp * b_T_tmp + c_T_tmp * d_T_tmp * beta;
    f_T_tmp[12] = x1;
    f_T_tmp[1] = e_T_tmp * b_T_tmp;
    f_T_tmp[5] = c_T_tmp * beta + std::sin(alpha1) * std::sin(beta1) * b_T_tmp;
    f_T_tmp[9] = -T_tmp * beta + std::cos(alpha1) * std::sin(beta1) * b_T_tmp;
    f_T_tmp[13] = b_y1;
    f_T_tmp[2] = -d_T_tmp;
    f_T_tmp[6] = T_tmp * e_T_tmp;
    f_T_tmp[10] = c_T_tmp * e_T_tmp;
    f_T_tmp[14] = z1;
    f_T_tmp[3] = 0.0F;
    f_T_tmp[7] = 0.0F;
    f_T_tmp[11] = 0.0F;
    f_T_tmp[15] = 1.0F;
    b_r_up[0] = r_up * std::sin(alpha);
    b_r_up[4] = r_up * std::sin(-alpha);
    b_r_up[8] = r_up * std::sin(alpha + -2.09439516F);
    b_r_up[12] = r_up * std::sin(-2.09439516F - alpha);
    b_r_up[16] = r_up * std::sin(alpha + 2.09439516F);
    b_r_up[20] = r_up * std::sin(2.09439516F - alpha);
    b_r_up[1] = r_up * std::cos(alpha);
    b_r_up[5] = r_up * std::cos(-alpha);
    b_r_up[9] = r_up * std::cos(alpha + -2.09439516F);
    b_r_up[13] = r_up * std::cos(-2.09439516F - alpha);
    b_r_up[17] = r_up * std::cos(alpha + 2.09439516F);
    b_r_up[21] = r_up * std::cos(2.09439516F - alpha);

    for(i = 0; i < 6; i++)
    {
        B_tmp_tmp = i << 2;
        B[B_tmp_tmp + 2] = 0.0F;
        B[B_tmp_tmp + 3] = 1.0F;
        b_r_up[B_tmp_tmp + 2] = 0.0F;
        b_r_up[B_tmp_tmp + 3] = 1.0F;
    }

    for(i = 0; i < 4; i++)
    {
        beta = f_T_tmp[i + 4];
        T_tmp = f_T_tmp[i + 8];
        b_T_tmp = f_T_tmp[i + 12];

        for(B_tmp_tmp = 0; B_tmp_tmp < 6; B_tmp_tmp++)
        {
            int i1;
            i1 = B_tmp_tmp << 2;
            C[i + i1] = ((f_T_tmp[i] * b_r_up[i1] + beta * b_r_up[i1 + 1]) + T_tmp *
                         b_r_up[i1 + 2]) + b_T_tmp * b_r_up[i1 + 3];
        }
    }

    b_r_up[2] = h_mid;
    b_r_up[6] = h_mid;
    b_r_up[10] = h_mid;
    b_r_up[14] = h_mid;
    b_r_up[18] = h_mid;
    b_r_up[22] = h_mid;

    for(i = 0; i < 6; i++)
    {
        B_tmp_tmp = i << 2;
        b_r_up[B_tmp_tmp] = 0.0F;
        b_r_up[B_tmp_tmp + 1] = 0.0F;
        b_r_up[B_tmp_tmp + 3] = 0.0F;
    }

    for(i = 0; i < 24; i++)
    {
        C[i] += b_r_up[i];
    }

    float a;
    float b_a;
    float c_a;
    float d_a;
    float e_a;
    float f_a;
    float g_a;
    float h_a;
    float i_a;
    float j_a;
    float k_a;

    // 动坐标系到静坐标系变换矩阵
    // 推杆初始距离
    beta = C[0] - B[0];
    T_tmp = C[1] - B[1];
    b_T_tmp = C[2] - B[2];
    c_T_tmp = C[4] - B[4];
    d_T_tmp = C[5] - B[5];
    e_T_tmp = C[6] - B[6];
    alpha = C[8] - B[8];
    a = C[9] - B[9];
    b_a = C[10] - B[10];
    c_a = C[12] - B[12];
    d_a = C[13] - B[13];
    e_a = C[14] - B[14];
    f_a = C[16] - B[16];
    g_a = C[17] - B[17];
    h_a = C[18] - B[18];
    i_a = C[20] - B[20];
    j_a = C[21] - B[21];
    k_a = C[22] - B[22];
    leg[0] = std::sqrt((beta * beta + T_tmp * T_tmp) + b_T_tmp * b_T_tmp);
    leg[1] = std::sqrt((c_T_tmp * c_T_tmp + d_T_tmp * d_T_tmp) + e_T_tmp * e_T_tmp);
    leg[2] = std::sqrt((alpha * alpha + a * a) + b_a * b_a);
    leg[3] = std::sqrt((c_a * c_a + d_a * d_a) + e_a * e_a);
    leg[4] = std::sqrt((f_a * f_a + g_a * g_a) + h_a * h_a);
    leg[5] = std::sqrt((i_a * i_a + j_a * j_a) + k_a * k_a);
}
