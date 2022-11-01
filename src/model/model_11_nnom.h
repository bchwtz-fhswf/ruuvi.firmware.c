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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_GRU_15_GRU_CELL_15_KERNEL_0 {-26, 37, 24, -33, 48, 28, -14, -9, 9, 38, -13, 31, 83, 23, 58, -25, -14, -2, -22, -8, 0, -117, -42, -4, -13, -9, -30, 16, -38, -1, 37, 36, 31, -24, 6, 33, -3, 1, -2, 39, 35, 41, 39, -27, 7, 43, 10, 39, 0, 7, -2, 17, 4, -28, -16, -29, -2, 33, -24, 5, 1, 4, 48, -32, 16, 8, -32, -31, 50, 29, -16, 0, 25, 8, -33, 15, 46, 8, -42, -13, 2, 10, -5, 15, 18, 0, 46, -39, -26, 35, -20, 35, 21, -24, 8, 2, 28, -21, 12, 15, 46, 16, -2, -42, -10, -2, -11, 0}

#define TENSOR_GRU_15_GRU_CELL_15_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_15_GRU_CELL_15_RECURRENT_KERNEL_0 {-7, 31, -53, -41, -18, -20, -16, 2, 20, 30, -18, 12, -30, 29, -51, -15, 26, 23, -43, 18, 61, 5, -8, 10, -11, 12, 8, 3, -20, -25, -41, 25, 17, 0, -22, 22, -51, -15, 9, 50, 22, -5, -5, 29, -70, -13, -12, 6, 44, -35, -41, -12, -20, -44, -2, 5, 17, -26, -40, -4, 66, -16, 8, -7, -40, 20, 13, -34, 17, 39, -17, -36, 38, -25, -14, 5, 0, 14, 21, 27, -12, -32, -31, 28, -82, 24, -3, 21, 25, -36, 38, 5, -11, 11, 9, -39, 11, 12, 12, -22, 28, 14, -16, -35, 25, -33, -26, 12, 24, -34, 16, 66, 41, 31, 29, 14, -22, 18, -5, 26, -9, 10, 28, -20, 18, -2, -14, 8, -31, -13, 32, -12, -4, -66, -18, -21, -28, 1, 2, 17, 31, 10, -17, 15, 36, -18, -1, 13, 31, -26, -28, 20, 22, -1, -11, -13, -22, -29, -2, -22, 25, -45, -3, -16, 3, 41, -20, -17, -36, 29, 28, -7, 13, -20, 12, 18, -40, -7, 9, -2, -7, 14, -45, 20, -20, 33, -27, 6, 43, -20, -4, -26, -10, 25, 31, -8, 9, 16, 2, -14, 20, 16, -5, 43, -7, -43, 46, -14, -34, -11, -13, 10, 5, 44, -10, -39, -30, 26, 56, -37, 7, 37, -12, 3, 7, 1, -21, -28, 6, 4, -20, 18, 12, 20, -18, -8, -15, -3, 42, 52, -25, -6, 52, -41, -15, 39, 34, -48, 9, 20, -14, 29, 41, -23, 31, -16, -3, 17, 8, 11, -19, 31, 2, -9, -16, -10, 63, -72, -18, 13, 31, -50, 3, -68, -1, -10, 41, -15, -4, 4, -9, -23, -17, 14, -36, -7, -19, 55, 9, 4, 16, -6, -8, 10, 22, -17, -39, 7, 0, 44, 31, 14, 3, 5, 19, -16, 3, 9, 7, -2, -33, 24, -6, 6, 7, -3, 16, -43, -20, 16, -9, -21, -15, -28, 11, 33, 4, 0, 34, 5, 14, -8, -14, 16, -28, -29, 34, -33, -8, 7, 21, -18, 0, 1, 11, -9, 16, -35, -29, -23, 8, 9, 6, -6, 36, -7, -6, -10, -34, -12, 15, 3, -32, 19, 1, 14, -18, -16, -1, 25, -8, 7, 11, -35, -10, -5, -17, 5, 25, -31, 8, -15, 35, 12, 12, -15, 35, 16, -33, 4, 5, 15, -14, 26, 1, -9, -10, -20, -1, 19, -24, 2, -4, -13, 2, 21, -46, -8, 23, 22, 15, 2, 1, -24, 48, 5, 8, 14, -14, 10, -1, 13, 21, 9, -3, -28, 31, 38, 8, 2, -41, 13}

#define TENSOR_GRU_15_GRU_CELL_15_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_15_GRU_CELL_15_BIAS_0 {-86, -38, 27, -29, 24, 10, -41, -62, -51, -42, -31, -36, 0, 7, -46, 39, -3, -29, -3, -24, -11, 6, 25, -34, 0, 8, 1, -2, 12, 12, 1, 4, -6, 7, -1, -3, -86, -38, 27, -29, 24, 10, -41, -62, -51, -42, -31, -36, 0, 7, -46, 39, -3, -29, -3, -24, -11, 6, 25, -34, 1, -4, 4, 9, 11, 6, 0, -15, 16, -15, -3, 12}

#define TENSOR_GRU_15_GRU_CELL_15_BIAS_0_DEC_BITS {6}

#define GRU_15_BIAS_LSHIFT {7}

#define GRU_15_OUTPUT_RSHIFT {6}

#define TENSOR_GRU_16_GRU_CELL_16_KERNEL_0 {7, -7, 0, 60, -27, 22, 65, 45, -16, -25, -11, -22, -48, -36, -24, 4, -13, 4, -8, 15, 10, 4, -59, -11, 17, -19, -17, 26, -5, -1, 29, -4, -21, 42, -18, -3, 62, 18, 31, -4, 21, -28, 0, -5, -29, -17, -19, 8, 19, 10, 6, 1, -30, 16, -3, -9, 14, 12, 6, -19, -18, 32, -13, -3, -12, 12, -37, -13, -14, -9, -27, -8, 19, 2, 12, 31, -19, 21, 21, -13, -13, 17, -24, -15, 52, -3, 19, -14, 32, 9, 6, 20, -15, 18, -45, 12, 11, 11, 22, 2, -10, -13, -27, -13, 34, 21, -13, -11, 16, -17, 1, -17, 11, -12, -5, -5, 8, -8, -6, -20, 21, 11, 1, -8, -17, 3, 13, 19, 8, -11, -10, -6, -3, 42, 14, -10, 4, 15, 19, 10, -10, -12, -3, -9, -22, -5, -13, -9, 1, 8, 1, -12, -57, -13, -18, -42, -36, 1, -11, 25, 18, 5, -10, -11, -2, 15, -15, 9, -3, 8, -15, -21, 31, -15, 15, 24, 12, 6, 9, 0, -10, 31, -5, -8, -13, 1, 12, 18, 15, -3, 13, 10, -4, 1, -3, -12, 0, -20, 12, -3, 37, 26, 7, -8, -9, 9, -3, 11, 15, 15, -10, 0, 7, 14, -7, 4, 2, 7, 15, -1, -20, -11, 25, -11, 0, -9, 13, -7, 19, -17, -4, 25, -22, -10, 5, 14, -5, -22, -19, -9, 20, 13, 10, -11, 15, 9, -8, 4, -9, -12, -11, -7, -14, 7, 8, 16, -12, -7, -4, -9, -7, -12, 4, 1, 11, 14, -11, -34, -5, 12, -1, -19, 16, -3, -16, -8, -3, 3, -12, -14, 11, 8, 10, 32, 28, 8, 4, 15, 17, -7, 13, 3, 26, -10, 26, -3, -7, -11, 12, -8, -11, -18, 3, -6, 6, -14, 2, -4, -2, -17, 3, -3, 5, 12, -3, -21, 9, -17, -6, 13, 0, -13, -10, 9, 15, -2, -14, 17, -6, 1, 7, -8, -5, 13, 14, -8, -4, 16, -11, -5, 0, -8, -8, 11, 12, 12, -17, -11, 18, 11, 10, -7, -13, -6, 16, -4, 4, -15, 1, 31}

#define TENSOR_GRU_16_GRU_CELL_16_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_16_GRU_CELL_16_RECURRENT_KERNEL_0 {-12, -2, -14, 9, 6, -11, 8, 29, -29, 11, -25, 24, 23, 32, 44, 7, -4, -6, 3, -10, 77, 4, -19, -2, -6, 67, 36, -24, 31, -13, -50, -65, -12, 18, -22, 19, 17, 35, 19, 20, -14, -14, 23, -21, 31, -10, 7, 13, 0, -5, -17, -28, 0, -26, 11, 3, -16, 9, 17, 11, -28, -4, -8, 16, -20, -13, 10, -24, 52, 34, 33, 3, 22, 10, -26, -34, -20, 21, -44, -25, 15, -57, -14, 14, -41, 42, 4, 4, -31, 11, -9, -10, -5, 0, 11, 22, 12, -1, 5, -13, 18, 9, 6, 28, 1, 8, -29, -7, 20, 36, -8, -7, 14, 14, 30, -8, 2, 7, -20, 9, 30, 8, -2, -9, -1, -6, -3, -1, -22, -3, -3, 24, 28, 18, 29, 29, 69, 9, 35, -15, -17, 1, 36, -8, 10, 11, -5, -25, -34, 9, -10, -40, 4, 19, 17, -6, -4, 4, -31, -3, 10, 23, 4, -18, -38, -34, -14, -8, 25, -14, 25, -11, -9, -1, -15, 14, 11, 44, -40, 1, 9, 24, 7, -28, -1, -45, -43, -1, 22, -27, -11, -28, -2, 25, -26, 20, 44, 17, -27, -10, 11, 18, -17, 0, 21, 17, 0, 32, -10, 21, -11, 1, 24, 24, 3, 4, 31, -32, -8, 13, -41, -4, 9, -14, -47, 17, -4, 8, -33, 25, 57, -5, -3, -2, 13, -1, 33, -19, -4, -10, -24, 8, 11, -9, 15, -15, -6, 18, -6, 0, 15, -9, -20, -25, -19, 1, 28, 43, -5, 20, 6, -18, 35, 8, -32, -30, -7, -9, -17, -34, 18, 0, 11, 10, -37, 17, -20, 28, -2, 29, -1, 22, 5, 44, 3, 24, 8, -5, 9, -7, 25, -36, -12, -9, 28, 32, -31, -8, 24, 35}

#define TENSOR_GRU_16_GRU_CELL_16_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_16_GRU_CELL_16_BIAS_0 {9, 53, 87, 83, 36, 28, 11, -36, 82, 77, 13, -42, 24, 7, -30, -2, -13, -2, 11, 14, 8, -3, 5, 8, 6, 2, -14, -19, 3, -4, 9, 53, 87, 83, 36, 28, 11, -36, 82, 77, 13, -42, 24, 7, -30, -2, -13, -2, 11, 14, -1, 10, 8, 11, 8, 3, -16, -7, 14, -7}

#define TENSOR_GRU_16_GRU_CELL_16_BIAS_0_DEC_BITS {6}

#define GRU_16_BIAS_LSHIFT {5}

#define GRU_16_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_17_GRU_CELL_17_KERNEL_0 {-21, -29, 22, 28, 13, 18, -10, -6, 28, 5, 14, -6, 26, 7, -26, 6, 21, -4, 7, 7, -21, 30, 49, 32, 17, 0, -9, 10, 4, -43, 31, -16, 74, 10, -6, -1, -46, -5, 14, 10, -18, -22, -19, 47, 8, 19, -1, -8, -8, 22, -10, 31, 6, 26, 11, 33, 18, 17, -21, -4, -5, -32, 14, 10, -82, -28, -7, -14, -41, 6, -2, 28, -3, 35, 36, -8, 3, -16, -6, 63, 15, -17, 20, -20, -5, 21, 6, 3, 14, -9, 15, -10, 6, 3, 22, -13, 58, 8, 21, 30, 43, -58, -45, 2, -10, 2, -33, 10, 16, 48, -93, -2, -3, 12, -13, 27, 5, 2, -7, 26, -12, -29, 73, -30, 6, -25, -24, 48, 27, 6, 67, -1, -10, 69, -27, 37, 43, 0, -16, -51, -11, -40, 23, -6, 25, 34, -23, -21, -12, 35, 33, 53, 33, -29, -61, -20, -43, 1, -3, -76, 25, 15, 20, -31, -40, 8, -10, -3, 23, -27, 31, -16, 30, 9, 14, -6, -1, 11, 5, -3, 19, -66, -24, -16, 22, -2, 8, 0, 10, 23, -65, 34, -17, -10, 20, 24, 40, -3, -28, 22, -13, 10, 6, -6, 26, 24, -1, 9, 4, 2, -3, -12, 4, 3, -11, -8, -16, 1, 23, 30, 13, -16, 26, 20, 6, 5, 13, 9, 1, 9, 28, 45, 0, 17, 2, 11, -22, 29, -2, -4}

#define TENSOR_GRU_17_GRU_CELL_17_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_17_GRU_CELL_17_RECURRENT_KERNEL_0 {-16, 21, 71, -4, 22, -8, 11, 32, 60, 90, -5, 71, 113, 49, 15, 126, 43, 103, 31, 0, 4, 36, 5, 19, -16, -59, 33, 25, -11, -43, 48, 8, -12, 49, -11, -55, 28, -11, -43, 20, 24, 53, 65, -6, 100, 24, 64, -30, 106, 19, 85, -37, -22, -34, 59, -9, -64, -47, 4, -46, -7, -51, 8, -33, -6, 97, -27, -58, 34, -32, -5, -46, 11, -30, -51, 68, 2, 2, -120, 55, -80, 2, -30, -26, -30, 22, -31, -20, -7, 11, -37, 26, -38, 46, 28, 54, 23, -9, -28, 67, 19, -1, 18, -47, 56, 7, -89, 57, -110, 41, -21, -45, -32, -41, -60, -69, -5, -94, 38, 37, 3, 10, -37, -44, 71, -10, 36, 23, 70, 46, -23, 18, -19, -2, 13, -63, -17, 9, 24, -37, 27, 21, -107, 56, 10, -56, -23, -35, 25, -34, 13, -34, 2, -36, 30, -19, -29, -2, 22, -1, -23, -19, 12, 49, 45, 9, 1, -3, -26, -28, 54, 30, 6, -11, 24, 1, -3, 86, 4, 1, 51, -9, 9, -1, 45, -8, 98, 43, 73, 20, 15, 70}

#define TENSOR_GRU_17_GRU_CELL_17_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_17_GRU_CELL_17_BIAS_0 {70, 33, 70, 89, 83, 49, 37, 77, 4, 3, -2, -27, 1, -3, -16, 7, -8, 16, 8, -9, 7, 21, -26, -6, 70, 33, 70, 89, 83, 49, 37, 77, 4, 3, -2, -27, 1, -3, -16, 7, -14, 45, 15, -9, -7, 20, -34, -27}

#define TENSOR_GRU_17_GRU_CELL_17_BIAS_0_DEC_BITS {6}

#define GRU_17_BIAS_LSHIFT {6}

#define GRU_17_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_5_KERNEL_0 {10, -22, -24, 31, 57, -44, -10, 5, -18, 34, -24, 22, 20, 7, 40, 19, 52, 83, 85, -20, -19, -31, -22, 11, 52, -5, -4, 54, -21, -66, -42, -30, -12, 30, -85, -61, 0, 22, -8, 21, -5, -57, -2, -104, -8, 6, 8, -16}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_5_BIAS_0 {86, -18, -94, -102, 13, 95}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {8}

#define DENSE_5_BIAS_LSHIFT {4}

#define DENSE_5_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define GRU_15_INPUT_OUTPUT_DEC 9
#define GRU_15_INPUT_OUTPUT_OFFSET 0
#define GRU_15_OUTPUT_DEC 7
#define GRU_15_OUTPUT_OFFSET 0
#define GRU_16_OUTPUT_DEC 7
#define GRU_16_OUTPUT_OFFSET 0
#define GRU_17_OUTPUT_DEC 7
#define GRU_17_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 4
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
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

const nnom_io_config_t gru_15_input_config = {
    .super = {.name = "gru_15_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_15_gru_cell_15_kernel_0_data[] = TENSOR_GRU_15_GRU_CELL_15_KERNEL_0;

const nnom_shape_data_t tensor_gru_15_gru_cell_15_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_kernel_0_dec[] = TENSOR_GRU_15_GRU_CELL_15_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_15_gru_cell_15_kernel_0 = {
    .p_data = (void*)tensor_gru_15_gru_cell_15_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_15_gru_cell_15_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_15_gru_cell_15_recurrent_kernel_0_data[] = TENSOR_GRU_15_GRU_CELL_15_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_15_gru_cell_15_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_recurrent_kernel_0_dec[] = TENSOR_GRU_15_GRU_CELL_15_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_15_gru_cell_15_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_15_gru_cell_15_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_15_gru_cell_15_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_15_gru_cell_15_bias_0_data[] = TENSOR_GRU_15_GRU_CELL_15_BIAS_0;

const nnom_shape_data_t tensor_gru_15_gru_cell_15_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_bias_0_dec[] = TENSOR_GRU_15_GRU_CELL_15_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_15_gru_cell_15_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_15_gru_cell_15_bias_0 = {
    .p_data = (void*)tensor_gru_15_gru_cell_15_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_15_gru_cell_15_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_15_gru_cell_15_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_15_gru_cell_config = {
    .super = {.name = "gru_15"},
    .weights = (nnom_tensor_t*)&tensor_gru_15_gru_cell_15_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_15_gru_cell_15_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_15_gru_cell_15_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_15_config = {
    .super = {.name = "gru_15"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_16_gru_cell_16_kernel_0_data[] = TENSOR_GRU_16_GRU_CELL_16_KERNEL_0;

const nnom_shape_data_t tensor_gru_16_gru_cell_16_kernel_0_dim[] = {12, 30};
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_kernel_0_dec[] = TENSOR_GRU_16_GRU_CELL_16_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_16_gru_cell_16_kernel_0 = {
    .p_data = (void*)tensor_gru_16_gru_cell_16_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_16_gru_cell_16_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_16_gru_cell_16_recurrent_kernel_0_data[] = TENSOR_GRU_16_GRU_CELL_16_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_16_gru_cell_16_recurrent_kernel_0_dim[] = {10, 30};
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_recurrent_kernel_0_dec[] = TENSOR_GRU_16_GRU_CELL_16_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_16_gru_cell_16_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_16_gru_cell_16_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_16_gru_cell_16_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_16_gru_cell_16_bias_0_data[] = TENSOR_GRU_16_GRU_CELL_16_BIAS_0;

const nnom_shape_data_t tensor_gru_16_gru_cell_16_bias_0_dim[] = {2, 30};
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_bias_0_dec[] = TENSOR_GRU_16_GRU_CELL_16_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_16_gru_cell_16_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_16_gru_cell_16_bias_0 = {
    .p_data = (void*)tensor_gru_16_gru_cell_16_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_16_gru_cell_16_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_16_gru_cell_16_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_16_gru_cell_config = {
    .super = {.name = "gru_16"},
    .weights = (nnom_tensor_t*)&tensor_gru_16_gru_cell_16_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_16_gru_cell_16_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_16_gru_cell_16_bias_0,
    .q_dec_z = 2,
    .q_dec_h = 7,
    .units = 10
};

const nnom_rnn_config_t gru_16_config = {
    .super = {.name = "gru_16"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_17_gru_cell_17_kernel_0_data[] = TENSOR_GRU_17_GRU_CELL_17_KERNEL_0;

const nnom_shape_data_t tensor_gru_17_gru_cell_17_kernel_0_dim[] = {10, 24};
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_kernel_0_dec[] = TENSOR_GRU_17_GRU_CELL_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_17_gru_cell_17_kernel_0 = {
    .p_data = (void*)tensor_gru_17_gru_cell_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_17_gru_cell_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_17_gru_cell_17_recurrent_kernel_0_data[] = TENSOR_GRU_17_GRU_CELL_17_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_17_gru_cell_17_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_recurrent_kernel_0_dec[] = TENSOR_GRU_17_GRU_CELL_17_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_17_gru_cell_17_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_17_gru_cell_17_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_17_gru_cell_17_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_17_gru_cell_17_bias_0_data[] = TENSOR_GRU_17_GRU_CELL_17_BIAS_0;

const nnom_shape_data_t tensor_gru_17_gru_cell_17_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_bias_0_dec[] = TENSOR_GRU_17_GRU_CELL_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_17_gru_cell_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_17_gru_cell_17_bias_0 = {
    .p_data = (void*)tensor_gru_17_gru_cell_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_17_gru_cell_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_17_gru_cell_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_17_gru_cell_config = {
    .super = {.name = "gru_17"},
    .weights = (nnom_tensor_t*)&tensor_gru_17_gru_cell_17_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_17_gru_cell_17_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_17_gru_cell_17_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_17_config = {
    .super = {.name = "gru_17"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_5_kernel_0_dec[] = TENSOR_DENSE_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_kernel_0 = {
    .p_data = (void*)tensor_dense_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_5_bias_0_data[] = TENSOR_DENSE_5_BIAS_0;

const nnom_shape_data_t tensor_dense_5_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_5_bias_0_dec[] = TENSOR_DENSE_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_bias_0 = {
    .p_data = (void*)tensor_dense_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_5_output_shift[] = DENSE_5_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_5_bias_shift[] = DENSE_5_BIAS_LSHIFT;
const nnom_dense_config_t dense_5_config = {
    .super = {.name = "dense_5"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_5_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_5_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_5_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_5_bias_shift
};

const nnom_softmax_config_t softmax_5_config = {
    .super = {.name = "softmax_5"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_5_OUTPUT_DEC};
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

	layer[0] = input_s(&gru_15_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_15_gru_cell_config), &gru_15_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_16_gru_cell_config), &gru_16_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_17_gru_cell_config), &gru_17_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_5_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_5_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_11_NNOM_H