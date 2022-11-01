#ifndef MODEL_8_NNOM_H
#define MODEL_8_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_8_nnom
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
#define TENSOR_GRU_21_GRU_CELL_21_KERNEL_0 {12, 13, -28, 55, -20, 4, 17, -24, 20, -80, 66, -43, 3, -14, -71, 55, 1, 81, -24, 0, 17, 54, -28, -54, 9, 69, -35, -120, -75, 18, -28, 17, 8, -54, -3, 79, -27, -48, 57, -73, -6, -15, 4, 64, -16, 21, -57, -29, 10, -65, -38, -43, 20, 43, 71, -36, -76, -1, -43, -25, 39, -44, -9, 36, -59, 20, 2, -7, -69, 28, 51, -94, 33, -9, 54, 23, -18, -4, -36, 61, 17, -21, 23, -32, 47, 50, -32, -25, 23, 1, 51, -75, 6, -12, 8, -12, -31, -27, 56, 96, 20, 54, 28, 0, 22, 15, -15, 10}

#define TENSOR_GRU_21_GRU_CELL_21_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_21_GRU_CELL_21_RECURRENT_KERNEL_0 {-34, -42, -13, -18, -1, -64, 17, -11, 28, 18, -43, 0, 24, 55, -9, -22, 37, 12, 42, 16, 18, -3, 9, -54, -27, -30, 43, -1, 13, -52, 4, 24, -30, -18, -37, -5, 18, 3, -30, 3, -12, -11, -46, -1, -5, -32, -7, -28, -18, 30, 16, 9, 5, -26, 25, 6, 8, -39, -14, 8, -28, 28, 30, -42, 29, 18, -2, 18, -55, 34, -21, 2, -5, 51, 54, -5, 31, -39, -7, -1, -70, 27, -59, -36, 43, -38, 26, -64, -55, 25, -2, 9, 25, -21, 14, -2, 16, 4, 32, 3, 58, -28, 39, -24, -8, -4, -4, 21, -39, 5, 9, -13, -3, -39, 2, -47, -21, 17, -9, -2, 36, 38, -20, -3, 25, -6, -33, 19, 24, 34, 12, 36, 3, -29, -37, 17, 2, 9, 4, -26, 2, 2, 24, -27, -1, 14, 5, 11, 7, 17, 6, 72, 7, -31, -10, 10, -21, -12, 35, -3, -21, -17, -32, 11, -10, 18, -15, 13, 7, 15, -21, -1, -5, -17, -45, 7, 2, 3, 31, 18, 1, -35, 22, -21, 2, 4, 5, 11, 0, -7, -4, 95, 6, -37, 4, -22, 8, 22, -37, 26, 8, 11, -35, -12, 22, -46, -34, 46, 15, -8, 8, 33, 36, -10, 14, -35, -18, -5, 17, 8, -7, -24, -7, 16, -24, -31, 12, 20, -1, 9, 11, 27, -25, 1, 14, -10, 10, -62, -50, -15, -16, -21, 5, -26, 10, 2, -28, -6, 5, 31, -23, -17, -34, 0, 15, 28, 6, 14, 5, -22, -55, -12, -25, -11, -22, -23, 23, 5, -4, 32, 10, -16, -50, -12, -24, 25, 2, 19, 39, 33, -34, -19, 21, -48, 24, 16, -10, -7, -5, -35, 10, 5, 10, -33, -12, -9, -12, 31, 7, -1, -15, 29, -6, 4, -10, 0, -6, -16, 8, -25, 15, -27, -2, -25, 6, 9, 17, -15, -1, 22, -6, -11, 5, -21, -18, 25, -5, 23, -18, -12, -22, -11, 23, -2, 26, 1, 16, 13, 8, 3, -19, -25, 17, -25, -9, 4, 2, 1, -9, 20, -5, -30, 11, -3, -3, -2, -1, 3, -17, 15, 2, 32, -7, -1, -1, -15, 5, 23, 6, 0, -29, 14, -3, -14, -2, -6, 5, 6, 7, -10, -45, -14, -19, -34, -18, -22, 12, -7, 13, -25, -16, -7, 8, 16, -12, -26, -17, 9, -10, -18, -15, 18, -10, 11, -21, 4, -16, 2, -4, -3, 2, -2, 8, -26, 24, 36, 3, -28, 2, 8, 5, -21, 17, -23, 15, -14, -2, -2, 2, -15, -14, 6}

#define TENSOR_GRU_21_GRU_CELL_21_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_21_GRU_CELL_21_BIAS_0 {-45, 37, -58, -78, -35, -44, -36, -72, -65, -11, -55, -18, -10, 11, 23, 11, -1, -5, -1, 23, -10, -2, -12, 16, -2, 2, 6, 2, 0, 6, -2, -1, 4, -7, 1, 11, -45, 37, -58, -78, -35, -44, -36, -72, -65, -11, -55, -18, -10, 11, 23, 11, -1, -5, -1, 23, -10, -2, -12, 16, 1, 1, -9, 12, 0, -5, 0, 5, -11, -6, -2, -3}

#define TENSOR_GRU_21_GRU_CELL_21_BIAS_0_DEC_BITS {6}

#define GRU_21_BIAS_LSHIFT {8}

#define GRU_21_OUTPUT_RSHIFT {7}

#define TENSOR_GRU_22_GRU_CELL_22_KERNEL_0 {-53, 12, -48, -31, -29, -2, -41, 3, 50, 3, -22, -61, 0, 25, -36, 36, 47, -8, 17, 26, 20, -67, 21, -26, -68, 31, 48, 34, 9, -6, 18, -32, -57, -32, -12, -3, -2, 48, 40, 37, -17, 22, 1, 13, -41, 0, -41, -19, 5, -49, -10, -29, 14, -10, -43, 0, 16, 38, -1, -52, 15, -28, -17, 22, 37, 11, 45, -45, 16, -21, 29, 11, 10, -53, 2, 19, 56, 5, 3, -37, -23, -24, -5, -33, 9, 39, 30, 30, 27, -44, 40, -43, 32, 23, -12, -19, 52, -3, 16, 2, -15, -31, 7, -36, -30, 55, -25, 13, -21, 5, -15, 11, 34, 23, 29, 1, 11, -19, -16, 13, 31, -18, 8, 1, -44, 20, -17, 9, -13, 8, -28, -14, 21, 46, -31, 22, -8, -8, -18, 31, -16, 26, -15, -26, -6, 11, 6, -13, 22, 32, 12, 21, 4, 1, 2, -40, -28, -18, -12, 25, 12, 36, 48, 61, 30, 15, -2, -30, 35, 5, 42, 35, 30, 46, -8, -56, -43, -25, -6, -23, -23, -4, -37, -6, 22, 3, 27, 12, 1, -9, 19, 26, -11, 42, -8, -3, -19, -15, -18, 3, 3, -11, -28, 1, 41, 19, -16, 10, 15, 8, 4, 12, 2, 16, -9, -14, -5, 3, 28, -78, -15, -26, 37, 24, -32, 4, -38, -50, -9, -14, -13, -19, -20, 0, -5, -12, -12, -18, 12, -8, -5, -55, -14, -1, -2, -1, -18, -4, -2, 33, -5, -58, 25, -9, -2, 63, -19, 27, -39, -18, -20, -20, 39, 6, -31, -25, 4, 33, -6, -8, 29, -31, 23, -30, 15, -18, 5, 11, 33, -3, 1, -20, -22, 4, 17, 10, -12, -5}

#define TENSOR_GRU_22_GRU_CELL_22_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_22_GRU_CELL_22_RECURRENT_KERNEL_0 {-44, -34, -9, -18, -51, 16, 23, 10, 8, -6, -10, -19, 3, 5, 64, 8, -17, 59, -8, -16, -13, -3, -7, 4, -1, 20, 33, -2, -45, 5, 3, -14, -6, -49, -17, 66, -27, -8, -15, -33, -16, -53, 52, 9, 2, 9, 49, -6, 17, 13, -7, -62, 19, -15, -15, 0, -43, -37, -25, 4, -11, 0, -21, -57, 0, 5, 26, 21, -33, -22, 27, -20, -22, 17, 16, -11, -30, -16, -4, -12, -9, -11, 11, -15, -11, 27, -30, 2, -8, -15, -11, -35, 2, 44, -27, 0, -12, 15, -10, 27, -9, 7, 6, -37, -7, 2, 5, -9, 1, -5, -7, 8, -8, -5, 5, 32, 5, -11, -9, 37, 6, -6, 14, 35, 4, -3, 7, 40, 13, -12, 49, 13, 14, 3, 43, 23, -1, -15, 23, -13, 27, 3, 0, 25, -8, -6, 2, -21, -13, -3, -3, 2, -2, -9, 7, -2, -16, -22, -8, -4, 15, 5, -10, 83, 6, 1, -20, -81, 11, 6, -14, 6, 0, 3, -6, 5, 5, -3, 7, 16, -14, 4, 7, 25, 20, -4, 9, 23, 0, 4, -2, 7}

#define TENSOR_GRU_22_GRU_CELL_22_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_22_GRU_CELL_22_BIAS_0 {50, -52, 11, 18, 26, 69, 2, 81, 4, -5, -12, -58, -7, 17, -17, 1, 6, -5, 14, -7, -10, -5, -4, 10, 50, -52, 11, 18, 26, 69, 2, 81, 4, -5, -12, -58, -7, 17, -17, 1, 5, 2, 13, 7, -9, -7, -10, 6}

#define TENSOR_GRU_22_GRU_CELL_22_BIAS_0_DEC_BITS {6}

#define GRU_22_BIAS_LSHIFT {6}

#define GRU_22_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_23_GRU_CELL_23_KERNEL_0 {-13, 39, 55, 73, 15, -10, 34, -31, -20, 61, 4, 14, 17, -11, 0, -14, -5, -29, -1, -9, -8, -17, 1, 2, -52, 5, -4, 32, 19, 28, -53, -32, 22, -20, 27, -4, -73, 15, 69, 22, 42, -18, 29, 0, -24, 47, -20, -33, -36, 12, 5, -4, -2, -17, -37, 9, -47, 6, -20, -15, -18, -7, -21, -13, 0, 3, -12, 7, -22, -11, -39, 4, -2, -3, 14, 17, -13, -21, -57, 10, 32, -84, -16, -3, 0, 18, -21, -18, 12, -13, -45, 13, 0, 27, 11, -52, -20, 7, 19, -20, -18, 16, 29, 2, -7, 68, -16, 1, 4, 19, 33, 24, -6, -4, 8, 8, -17, -66, -14, 13, -7, -26, 20, 22, -24, -17, -13, 17, -8, -40, 0, 9, 5, -35, -5, -31, -29, -9, -4, -10, 12, -26, -2, -1}

#define TENSOR_GRU_23_GRU_CELL_23_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_23_GRU_CELL_23_RECURRENT_KERNEL_0 {-107, 5, -15, -99, -45, 10, -36, -20, 22, 51, 15, 5, 61, 24, -14, 26, 51, 76, 69, 14, 43, 46, -111, 15, -66, -21, -60, 15, 51, 17, -12, 43, 55, 41, 28, 21, -20, -6, -41, -3, 126, 26, 30, -52, 78, -11, 33, 34, -54, -6, -42, 6, 34, -107, -18, -40, -14, -5, -20, 67, 7, 40, -69, -15, 0, -9, 63, -13, 46, 12, 48, 127, -4, 13, 40, 66, -3, -53, -5, -45, 50, 3, 83, 18, 31, 27, 21, 41, 29, -4, 42, 30, 37, 6, 22, 25, 26, 26, -51, 25, 6, 24, 28, 48, 35, 67, -33, 26}

#define TENSOR_GRU_23_GRU_CELL_23_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_23_GRU_CELL_23_BIAS_0 {70, 78, 83, 65, 79, 119, 13, -4, 4, 59, -35, 14, -45, 12, 10, 46, 48, -80, 70, 78, 83, 65, 79, 119, 13, -4, 4, 59, -35, 14, 16, 10, 35, 51, 16, 8}

#define TENSOR_GRU_23_GRU_CELL_23_BIAS_0_DEC_BITS {7}

#define GRU_23_BIAS_LSHIFT {5}

#define GRU_23_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_7_KERNEL_0 {-16, -50, -78, 50, 13, -43, 22, 28, -22, -11, -27, -51, -55, 18, 40, 19, 47, -42, -2, -15, -29, -49, 14, 62, 30, 22, -59, 11, -53, -51, 43, 46, 3, 1, 5, 42}

#define TENSOR_DENSE_7_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_7_BIAS_0 {79, 83, -29, -105, 28, -14}

#define TENSOR_DENSE_7_BIAS_0_DEC_BITS {7}

#define DENSE_7_BIAS_LSHIFT {5}

#define DENSE_7_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define GRU_21_INPUT_OUTPUT_DEC 9
#define GRU_21_INPUT_OUTPUT_OFFSET 0
#define GRU_21_OUTPUT_DEC 7
#define GRU_21_OUTPUT_OFFSET 0
#define GRU_22_OUTPUT_DEC 7
#define GRU_22_OUTPUT_OFFSET 0
#define GRU_23_OUTPUT_DEC 7
#define GRU_23_OUTPUT_OFFSET 0
#define DENSE_7_OUTPUT_DEC 4
#define DENSE_7_OUTPUT_OFFSET 0
#define SOFTMAX_7_OUTPUT_DEC 7
#define SOFTMAX_7_OUTPUT_OFFSET 0

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

const nnom_io_config_t gru_21_input_config = {
    .super = {.name = "gru_21_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_21_gru_cell_21_kernel_0_data[] = TENSOR_GRU_21_GRU_CELL_21_KERNEL_0;

const nnom_shape_data_t tensor_gru_21_gru_cell_21_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_kernel_0_dec[] = TENSOR_GRU_21_GRU_CELL_21_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_21_gru_cell_21_kernel_0 = {
    .p_data = (void*)tensor_gru_21_gru_cell_21_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_21_gru_cell_21_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_21_gru_cell_21_recurrent_kernel_0_data[] = TENSOR_GRU_21_GRU_CELL_21_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_21_gru_cell_21_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_recurrent_kernel_0_dec[] = TENSOR_GRU_21_GRU_CELL_21_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_21_gru_cell_21_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_21_gru_cell_21_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_21_gru_cell_21_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_21_gru_cell_21_bias_0_data[] = TENSOR_GRU_21_GRU_CELL_21_BIAS_0;

const nnom_shape_data_t tensor_gru_21_gru_cell_21_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_bias_0_dec[] = TENSOR_GRU_21_GRU_CELL_21_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_21_gru_cell_21_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_21_gru_cell_21_bias_0 = {
    .p_data = (void*)tensor_gru_21_gru_cell_21_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_21_gru_cell_21_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_21_gru_cell_21_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_21_gru_cell_config = {
    .super = {.name = "gru_21"},
    .weights = (nnom_tensor_t*)&tensor_gru_21_gru_cell_21_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_21_gru_cell_21_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_21_gru_cell_21_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_21_config = {
    .super = {.name = "gru_21"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_22_gru_cell_22_kernel_0_data[] = TENSOR_GRU_22_GRU_CELL_22_KERNEL_0;

const nnom_shape_data_t tensor_gru_22_gru_cell_22_kernel_0_dim[] = {12, 24};
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_kernel_0_dec[] = TENSOR_GRU_22_GRU_CELL_22_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_22_gru_cell_22_kernel_0 = {
    .p_data = (void*)tensor_gru_22_gru_cell_22_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_22_gru_cell_22_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_22_gru_cell_22_recurrent_kernel_0_data[] = TENSOR_GRU_22_GRU_CELL_22_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_22_gru_cell_22_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_recurrent_kernel_0_dec[] = TENSOR_GRU_22_GRU_CELL_22_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_22_gru_cell_22_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_22_gru_cell_22_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_22_gru_cell_22_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_22_gru_cell_22_bias_0_data[] = TENSOR_GRU_22_GRU_CELL_22_BIAS_0;

const nnom_shape_data_t tensor_gru_22_gru_cell_22_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_bias_0_dec[] = TENSOR_GRU_22_GRU_CELL_22_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_22_gru_cell_22_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_22_gru_cell_22_bias_0 = {
    .p_data = (void*)tensor_gru_22_gru_cell_22_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_22_gru_cell_22_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_22_gru_cell_22_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_22_gru_cell_config = {
    .super = {.name = "gru_22"},
    .weights = (nnom_tensor_t*)&tensor_gru_22_gru_cell_22_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_22_gru_cell_22_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_22_gru_cell_22_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_22_config = {
    .super = {.name = "gru_22"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_23_gru_cell_23_kernel_0_data[] = TENSOR_GRU_23_GRU_CELL_23_KERNEL_0;

const nnom_shape_data_t tensor_gru_23_gru_cell_23_kernel_0_dim[] = {8, 18};
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_kernel_0_dec[] = TENSOR_GRU_23_GRU_CELL_23_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_23_gru_cell_23_kernel_0 = {
    .p_data = (void*)tensor_gru_23_gru_cell_23_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_23_gru_cell_23_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_23_gru_cell_23_recurrent_kernel_0_data[] = TENSOR_GRU_23_GRU_CELL_23_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_23_gru_cell_23_recurrent_kernel_0_dim[] = {6, 18};
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_recurrent_kernel_0_dec[] = TENSOR_GRU_23_GRU_CELL_23_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_23_gru_cell_23_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_23_gru_cell_23_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_23_gru_cell_23_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_23_gru_cell_23_bias_0_data[] = TENSOR_GRU_23_GRU_CELL_23_BIAS_0;

const nnom_shape_data_t tensor_gru_23_gru_cell_23_bias_0_dim[] = {2, 18};
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_bias_0_dec[] = TENSOR_GRU_23_GRU_CELL_23_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_23_gru_cell_23_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_23_gru_cell_23_bias_0 = {
    .p_data = (void*)tensor_gru_23_gru_cell_23_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_23_gru_cell_23_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_23_gru_cell_23_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_23_gru_cell_config = {
    .super = {.name = "gru_23"},
    .weights = (nnom_tensor_t*)&tensor_gru_23_gru_cell_23_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_23_gru_cell_23_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_23_gru_cell_23_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .units = 6
};

const nnom_rnn_config_t gru_23_config = {
    .super = {.name = "gru_23"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_7_kernel_0_data[] = TENSOR_DENSE_7_KERNEL_0;

const nnom_shape_data_t tensor_dense_7_kernel_0_dim[] = {6, 6};
const nnom_qformat_param_t tensor_dense_7_kernel_0_dec[] = TENSOR_DENSE_7_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_7_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_7_kernel_0 = {
    .p_data = (void*)tensor_dense_7_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_7_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_7_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_7_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_7_bias_0_data[] = TENSOR_DENSE_7_BIAS_0;

const nnom_shape_data_t tensor_dense_7_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_7_bias_0_dec[] = TENSOR_DENSE_7_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_7_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_7_bias_0 = {
    .p_data = (void*)tensor_dense_7_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_7_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_7_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_7_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_7_output_shift[] = DENSE_7_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_7_bias_shift[] = DENSE_7_BIAS_LSHIFT;
const nnom_dense_config_t dense_7_config = {
    .super = {.name = "dense_7"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_7_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_7_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_7_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_7_bias_shift
};

const nnom_softmax_config_t softmax_7_config = {
    .super = {.name = "softmax_7"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_7_OUTPUT_DEC};
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

	layer[0] = input_s(&gru_21_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_21_gru_cell_config), &gru_21_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_22_gru_cell_config), &gru_22_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_23_gru_cell_config), &gru_23_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_7_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_7_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_8_NNOM_H