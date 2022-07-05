#ifndef MODEL_11_NNOM_H
#define MODEL_11_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_11_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (10)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (192)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (32)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.24075012569983611f, -0.24075012569983611f, 0.0f, 0.24074851273755382f, -0.0f, 0.25f, -0.5f, 0.25f, 0.49040304612512053f, -0.24075173866211835f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0 {43, -31, 7, 65, 14, 30, -9, -14, -3, -13, -1, -38, 7, 7, -33, -38, -35, -4, -36, 44, -20, -18, -24, 20, 31, 0, -37, -25, 9, -14, 6, 1, 11, -25, 7, -26, -10, -18, 37, 2, 61, 33, 9, -44, 12, -16, -29, -27, -10, 4, -24, -18, 25, 49, 31, -3, -24, 38, 20, 37, 10, -26, -60, 7, 52, -18, 35, -2, 4, 68, -9, 23, 55, 43, 26, 7, -31, -45, 24, 11, 2, 14, -3, 17, 7, 14, 32, 15, 34, 6, 32, -47, -4, -9, 9, -3, -18, -10, 31, -11, -21, -26, 14, 38, -6, 5, -8, 11}

#define TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0 {-43, 66, -49, 25, 50, -4, -29, -75, 26, -61, 42, -54, -25, 62, -39, 26, -14, 21, -47, 43, 0, -29, 20, -30, -44, -16, -15, 10, 47, -57, -64, -8, 52, -3, -30, 13, 33, -19, -2, 31, 18, -8, 36, -14, -43, 55, 42, 37, 99, 73, 15, -12, 4, -53, 50, 11, -4, -23, -28, -50, -6, -67, -17, -16, 37, 24, -7, 40, 65, -59, 54, -49, 1, 28, -38, -75, 31, -8, -14, 52, -25, 8, 60, -21, 72, -41, -37, 5, -70, -33, -4, 72, 8, -26, 27, -44, -53, 52, 41, -26, -15, -21, -47, -6, 34, 5, 41, -46, 56, -21, 7, -28, 40, 5, 54, -23, 39, -46, 53, -44, 84, -25, 14, -17, 27, -78, -30, 32, 28, -24, -43, 17, 54, -31, -27, 52, 35, -38, 3, -13, 10, -21, 12, -62, -21, 8, 5, -20, -30, -23, 48, -30, -58, -6, -47, -8, -40, 39, -3, -24, -9, 10, -3, -7, -30, 6, 29, 10, 17, -18, 25, -10, 25, 18, 29, 8, -7, 31, 47, 0, 3, 86, -10, 1, -10, 14, 6, 17, -25, 17, -23, 24, -14, -21, 0, -24, 1, 9, 8, 10, -13, -33, -14, 5, 10, -19, 13, -8, 6, 4, -14, 2, -15, -26, 0, -6, 14, 56, 6, 26, -7, -9, 4, -27, 28, 31, -6, -9, 2, -6, 24, -40, 21, 23, 18, 1, -6, -9, -27, 8, 21, 26, -28, -19, 7, 12, 6, -7, 12, 15, -6, 2, -30, -29, -3, -62, 46, 8, -8, -18, -48, 25, -37, -9, -5, 14, -36, -16, -27, 15, -8, -27, -8, 30, -3, 10, -36, 8, -20, -1, 15, -6, 56, 22, -29, -5, -16, -29, 22, 7, -5, 7, 7, -3, 6, 4, 33, 0, 2, 32, 3, -11, -6, -5, 22, 32, 22, 7, -19, 28, 0, 21, -8, 4, 1, 3, 4, 32, 16, 10, 20, -8, -5, 18, 19, 8, 2, -22, -4, 28, 19, -4, -26, 10, -31, -4, -17, -22, -34, -3, -13, -14, -16, -19, 24, -4, 19, -6, -1, 22, 2, 17, 17, 14, -10, 2, -25, 13, -6, -4, 3, 3, -5, 23, -2, -11, 18, 2, 3, 3, -2, -45, -17, 31, 12, 5, -13, -2, 18, 1, -4, 7, 6, 13, 2, 17, 5, -22, 12, -23, 10, -19, -16, 23, -3, 21, 25, 16, 8, 10, -6, 7, 19, 44, -4, -45, -20, -29, 30, 4, -13, 5, 27, -34, -7, -10, 38, 43, -9, 11, 24, -2, 16, -16, -14, 31, -11, 24, 4, 7, -4, 21}

#define TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0 {-6, 1, -69, 8, -47, -65, -5, -3, -36, -84, -13, -37, -22, 12, -7, -28, 5, 5, -24, -16, -7, 64, 5, 24, 8, 2, -5, -4, -2, -4, -5, -4, 5, 0, 2, 1, -6, 1, -69, 8, -47, -65, -5, -3, -36, -84, -13, -37, -22, 12, -7, -28, 5, 5, -24, -16, -7, 64, 5, 24, 14, 4, 7, -6, -2, 2, -3, -4, -8, 6, 8, 0}

#define TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS {6}

#define GRU_3_BIAS_LSHIFT {5}

#define GRU_3_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0 {-14, -7, -42, -33, -20, -54, -7, 29, 21, 38, 24, 28, -34, -13, 48, 45, -22, 7, -8, -44, -5, 9, -4, 6, -27, -1, 42, -61, 6, 12, 64, 42, -15, -8, 24, 17, -34, 1, 46, 26, 18, 3, -6, 39, 0, -24, -31, -36, -9, -28, 23, 32, -17, 6, 14, 8, -30, -15, 1, 13, -62, 69, 20, 50, -16, -1, 5, 19, -38, 60, -30, 57, 8, 4, 38, 30, 8, 58, 60, 13, -26, -39, -20, 17, -30, 58, 58, 76, -7, -21, -19, -20, -37, 36, -69, 28, -6, -14, 62, 25, -48, 22, 0, -16, 42, -59, 4, -36, 5, -22, 22, 16, 78, -34, 47, -50, 21, 0, 45, -36, 78, 6, -70, 52, 34, -8, 53, -15, 70, -7, -75, -7, 27, 31, -32, 33, 7, -6, 62, -28, 41, 40, 16, 31, -11, -25, -29, 3, 23, -9, 8, -5, -4, -14, -30, 2, -16, -25, 1, 0, -11, 6, 19, -35, 4, -29, -38, -33, -26, -32, 3, -25, -20, -29, -11, -8, -34, 12, 41, 6, 7, 0, 0, -44, -25, 18, -10, -14, -31, -2, -10, -5, -11, -20, -6, -1, -4, 37, 4, -51, -12, -64, -12, 4, -19, -25, -11, -62, -21, 19, -55, 2, 5, -51, 28, -42, -26, -49, 19, -14, 46, -41, -32, -13, -17, -36, 85, -60, 37, -46, -123, -27, 30, 12, -21, -13, -13, -11, 39, 0, 27, -9, 16, 12, 1, -9, -43, -10, 5, 2, -20, 7, -15, 14, -33, 21, -6, 9, -5, 5, 17, 9, 2, 19, 8, 10, -30, 21, -20, 22, -9, 26, 2, 7, 9, 5, -13, 23, 15, -10, -21, -25, -12, -30, -35, 13, -8, 21, 0, -1, -28, 8, -11, 1, -8, 0, 31, -14, -10, -14, 15, 13, 21, 15, 21, -5, -24, 16, 10, 3, 14, 15, -4, -17, -25, -4, 53, 11, -10, 22, 31, -16, 13, -18, 30, 21, -54, -4, 2, -23, -23, 14, -5, -10, 10, -34, 26, 1, 0, 1, 35, -6, 3, 10, 3, 88, 2, -28, 31, -19, -16, -7, 29, -11, -9, -26, -22, 21, -27, 2}

#define TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0 {-8, -1, 13, 26, 18, 3, -1, 1, -34, 23, -16, -33, -14, -17, -35, -6, 8, 8, -26, 38, 47, 30, -5, -5, 17, -16, 14, 20, 1, 28, 6, 9, -8, 13, 34, -5, 1, 1, 9, 38, -2, 2, -20, 16, 13, -19, -4, 6, -18, -28, -6, -12, 16, 5, -20, -40, 32, 39, -6, -40, -22, 26, -24, 5, 16, 15, -1, -4, 38, -2, 4, 44, 19, 0, -6, 31, -11, 39, -25, -19, -39, 10, -10, 3, -3, 31, -5, 1, 23, 2, -37, 7, -43, 0, -3, 6, 8, 32, 16, -33, 16, 33, -18, -12, 13, -1, 24, 5, 39, -6, 34, 15, 78, 9, 3, 7, 28, -21, -28, -22, 18, 1, 11, 4, 4, 4, 0, -12, 14, -15, 11, -13, -1, -23, -27, -21, 28, 33, -6, -33, -13, 35, 3, -21, -26, -4, 11, 4, 3, -5, -14, 14, -21, 16, 6, -25, 9, 8, 30, 5, 26, 11, 3, 8, -2, -11, -7, -21, -9, -9, 3, 1, -11, 31, -4, 8, 20, 1, -15, -14, -2, 5, -8, 2, -28, -4, 2, 20, -16, -38, -2, 2, -31, -16, -7, 6, -31, -22, -5, 13, 21, -9, 20, 8, -4, -1, -2, 27, -6, -7, 38, -5, 21, 9, 0, 10, 0, -10, -25, -16, 14, -22, -7, -3, 3, -5, 5, -2, 11, -1, 6, -20, -10, -10, -16, -25, 7, -5, 13, -15, 17, 5, 19, -29, 16, 13, 7, -11, 14, 9, -9, 8, -6, 5, 3, 10, 38, -6, -16, 15, -3, 3, -1, -21, 4, -1, 8, 1, 28, 32, 0, 13, 3, 8, 10, 31, 12, -5, -10, 14, -1, 7, 6, 10, -2, -10, 33, 11, 27, -6, 13, -26, -2, -3, 23, -6, -18, -15, 3, 8}

#define TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0 {79, -17, 70, 21, 73, 43, 67, 53, 83, -11, 0, -8, -14, 6, 0, -7, -32, -16, -30, -20, -9, -17, 16, -14, -17, 19, -14, -12, 17, 7, 79, -17, 70, 21, 73, 43, 67, 53, 83, -11, 0, -8, -14, 6, 0, -7, -32, -16, -30, -20, -28, -24, 24, -21, -12, 20, -4, -9, 9, 6}

#define TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS {6}

#define GRU_4_BIAS_LSHIFT {6}

#define GRU_4_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0 {0, -42, -59, -86, -9, -56, -94, 20, -29, 36, -8, -43, 53, 11, -31, -25, 31, -39, -5, 109, -12, -65, 56, 24, 21, -44, -2, -50, -76, 18, -32, 28, 17, 11, -39, 95, 19, 36, 20, 5, 16, -1, -100, -56, 60, -42, -5, -2, 59, 26, -31, -14, 123, -43, 31, -71, 11, -101, 35, 61, 77, 6, -4, 10, -34, -40, -46, -14, -60, 42, 59, -16, 8, 56, 95, 13, -12, 8, -18, -1, -19, 36, 33, 29, 35, -3, 81, 57, -13, -40, -42, 18, 24, 58, -12, 25, -33, 37, 23, 75, 76, 27, 12, -38, 11, -2, 29, 81, -29, -26, -89, -58, 26, 19, 74, 40, -27, -66, 29, 0, 61, 14, 3, 70, 109, 23, -34, 1, -75, -17, -54, 19, -11, -41, -38, -1, 41, 27, -107, -51, 80, 69, -16, -2, -35, 26, -81, 21, -56, 86, -7, 44, 21, 39, 43, 7, -24, 73, 122, -24, 13, 40, -15, 24, -48, 2, 6, 1, 24, -48, -47, 59, 34, -5, -15, 13, 12, 29, 37, 7, -14, 0, 23, 3, -1, 41, 37, 68, -35, -51, -76, -27, -11, 26, 113, -5, -29, -84, -16, -31, 53, -51, 6, 9, -51, -83, -62, -6, -42, -53, 24, 5, 16, -20, -3, -4, 67, -9, -64, -12, -104, 14, 61, -8, -14, 37, 12, 16, 1, 49, -5, 42, 3, 36, -28, -60, 39, 42, 20, -30}

#define TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0 {20, 37, 10, 11, 25, 28, 7, 41, 7, -104, -62, -35, -61, -35, -67, -118, 15, -13, 18, 64, -19, -51, 104, 28, 57, -2, -23, -63, 24, 31, 19, 28, 12, 31, -37, -54, -19, 26, 25, 10, -22, -16, -33, -64, 64, 28, 39, -40, -14, -12, -18, 17, -85, 39, -93, 55, 56, -11, -14, 17, -2, 2, 82, -11, 30, -2, -8, 11, -7, -39, -29, -112, -2, -26, -51, 9, 24, 70, -22, 6, 12, -2, 26, -43, 1, -61, 7, -23, -36, 19, 15, 18, -46, -18, -1, 72, 19, -37, -2, 18, 62, 21, -15, -3, 22, 14, -4, -7, 13, -21, 30, -61, -10, -1, 36, 9, -7, -8, -30, -10, -15, -41, -4, 13, -13, 4, -63, 63, 30, 35, 27, 32, -11, -5, -2, 47, -24, -59, 17, 6, -1, -26, -8, 36, 18, -6, 21, -16, -47, 82, 65, -34, -32, 23, -19, -1, -8, -23, 13, -73, 16, -18, 4, 20, 22, 36, -52, -53, -11, -24, -3, -7, 4, 41, 17, 11, 29, -5, 23, 94, -46, -57, -39, -18, -49, 14, -41, -4, 26, 35, -41, 43}

#define TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0 {85, 12, 44, 71, 126, 68, -127, 127, 49, -46, -8, -37, -70, -38, 19, 29, 7, -46, 14, -35, -56, -21, 53, -28, 85, 12, 44, 71, 126, 68, -127, 127, 49, -46, -8, -37, -70, -38, 19, 29, 14, -39, 16, -48, -29, 8, 40, -8}

#define TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS {7}

#define GRU_5_BIAS_LSHIFT {6}

#define GRU_5_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_1_KERNEL_0 {-70, 68, -44, -12, 13, 7, -17, 5, 8, 2, -2, 0, 22, -29, 21, -15, 23, 50, -8, -19, -34, -4, 35, 17, -25, 7, -80, -19, 31, -14, 26, 46, -13, -15, 21, 75, 12, -19, 4, -57, -46, -21, 37, -4, -30, 22, 20, 2}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_1_BIAS_0 {64, -31, -6, -99, 24, 35}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {8}

#define DENSE_1_BIAS_LSHIFT {4}

#define DENSE_1_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define GRU_3_INPUT_OUTPUT_DEC 7
#define GRU_3_INPUT_OUTPUT_OFFSET 0
#define GRU_3_OUTPUT_DEC 7
#define GRU_3_OUTPUT_OFFSET 0
#define GRU_4_OUTPUT_DEC 7
#define GRU_4_OUTPUT_OFFSET 0
#define GRU_5_OUTPUT_DEC 7
#define GRU_5_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 4
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {7};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t gru_3_input_config = {
    .super = {.name = "gru_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_3_gru_cell_3_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_kernel_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_kernel_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_data[] = TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_3_gru_cell_3_bias_0_data[] = TENSOR_GRU_3_GRU_CELL_3_BIAS_0;

const nnom_shape_data_t tensor_gru_3_gru_cell_3_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_bias_0_dec[] = TENSOR_GRU_3_GRU_CELL_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_3_gru_cell_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_3_gru_cell_3_bias_0 = {
    .p_data = (void*)tensor_gru_3_gru_cell_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_3_gru_cell_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_3_gru_cell_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_3_gru_cell_config = {
    .super = {.name = "gru_3"},
    .weights = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_3_gru_cell_3_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_3_config = {
    .super = {.name = "gru_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_4_gru_cell_4_kernel_0_data[] = TENSOR_GRU_4_GRU_CELL_4_KERNEL_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_kernel_0_dim[] = {12, 30};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_kernel_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_kernel_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_data[] = TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_dim[] = {10, 30};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_4_gru_cell_4_bias_0_data[] = TENSOR_GRU_4_GRU_CELL_4_BIAS_0;

const nnom_shape_data_t tensor_gru_4_gru_cell_4_bias_0_dim[] = {2, 30};
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_bias_0_dec[] = TENSOR_GRU_4_GRU_CELL_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_4_gru_cell_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_4_gru_cell_4_bias_0 = {
    .p_data = (void*)tensor_gru_4_gru_cell_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_4_gru_cell_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_4_gru_cell_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_4_gru_cell_config = {
    .super = {.name = "gru_4"},
    .weights = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_4_gru_cell_4_bias_0,
    .q_dec_z = 2,
    .q_dec_h = 7,
    .units = 10
};

const nnom_rnn_config_t gru_4_config = {
    .super = {.name = "gru_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_5_gru_cell_5_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_kernel_0_dim[] = {10, 24};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_kernel_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_kernel_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_data[] = TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_5_gru_cell_5_bias_0_data[] = TENSOR_GRU_5_GRU_CELL_5_BIAS_0;

const nnom_shape_data_t tensor_gru_5_gru_cell_5_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_bias_0_dec[] = TENSOR_GRU_5_GRU_CELL_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_5_gru_cell_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_5_gru_cell_5_bias_0 = {
    .p_data = (void*)tensor_gru_5_gru_cell_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_5_gru_cell_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_5_gru_cell_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_5_gru_cell_config = {
    .super = {.name = "gru_5"},
    .weights = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_5_gru_cell_5_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_5_config = {
    .super = {.name = "gru_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_1_kernel_0_dec[] = TENSOR_DENSE_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_kernel_0 = {
    .p_data = (void*)tensor_dense_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_1_bias_0_data[] = TENSOR_DENSE_1_BIAS_0;

const nnom_shape_data_t tensor_dense_1_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_1_bias_0_dec[] = TENSOR_DENSE_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_bias_0 = {
    .p_data = (void*)tensor_dense_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_1_output_shift[] = DENSE_1_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_1_bias_shift[] = DENSE_1_BIAS_LSHIFT;
const nnom_dense_config_t dense_1_config = {
    .super = {.name = "dense_1"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_1_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_1_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_1_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_1_bias_shift
};

const nnom_softmax_config_t softmax_1_config = {
    .super = {.name = "softmax_1"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_1_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_io_config_t output0_config = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create(nnom_status_t *state)
{
	static nnom_model_t model;
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_3_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_3_gru_cell_config), &gru_3_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_4_gru_cell_config), &gru_4_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_5_gru_cell_config), &gru_5_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_1_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_1_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_11_NNOM_H