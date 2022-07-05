#ifndef HAR_GRU_NNOM_H
#define HAR_GRU_NNOM_H

#define APP_ACTIVITY_MODEL_NAME har_GRU_nnom
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
#define TENSOR_GRU_27_GRU_CELL_27_KERNEL_0 {65, -38, 12, -52, 25, -2, -8, -13, 4, 21, -10, 8, -28, -31, -58, -9, 5, -60, 16, 5, 27, 21, 19, -1, -23, -17, 15, 45, 41, -12, 31, 77, 0, -62, 6, -24, 9, -22, 17, 16, 71, 11, 2, -7, 33, -4, 27, 5, -12, -20, -24, -10, 26, 15, -1, -17, -40, 23, -20, 19, 22, 37, -19, -4, 14, -12, -35, 4, 54, 1, -3, 35, -2, -9, 15, -3, -8, 45, 30, -34, 13, 8, 0, -7, -21, -41, 32, -36, 12, -47, -9, 41, 4, -5, 5, 3, 5, 27, -18, 28, 42, -28, 38, -25, -2, -16, 18, -2}

#define TENSOR_GRU_27_GRU_CELL_27_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0 {30, 1, 93, -14, 0, -11, -42, 79, -8, 28, -26, 1, -16, 37, -68, -21, 24, 25, -34, -26, 10, 36, 6, 32, -15, 22, 69, -35, 7, -27, 16, 6, -4, -27, 58, -10, -40, -50, -12, 0, -12, 32, -27, -47, -19, 10, 22, 28, 15, -12, 13, -1, 35, -54, 58, -34, -7, 5, -43, -26, -42, -25, 29, 32, 36, 49, -4, -50, 15, -65, -21, 43, -53, -6, 7, 36, 8, 25, 2, -28, 12, -62, 59, 71, -6, 31, 14, -33, 3, 55, 5, -30, 7, 17, -35, -43, 23, -4, 62, 87, -38, 7, 42, 10, -7, 2, -16, -36, -56, -12, 40, 25, -10, 22, 21, 41, -44, 13, 50, 48, -11, -5, 36, 6, 5, -14, 19, -17, -15, 31, 11, -22, 30, 19, -38, 14, 90, -21, -3, 0, -53, 49, 28, 10, -1, 25, 9, -25, 0, 3, 51, 9, 56, -24, -46, 21, 14, -2, 50, -24, 7, -10, 7, 14, -6, -16, 22, -29, 17, 23, 2, -60, -46, 1, 33, 3, 7, 33, 26, -21, -6, 17, 26, 11, -24, -13, -8, 49, 31, -12, -74, -12, -3, 9, 38, -14, -28, 1, -21, 10, -2, -4, -3, -19, 16, 20, 42, -6, 9, 32, -22, 9, 30, -3, 57, -22, 44, -26, -16, -29, 20, -32, 11, -7, 26, -26, -22, 23, 15, 8, 5, -5, -48, 11, 25, 21, 43, -2, -23, -39, -6, -18, -17, 19, -4, -2, -24, 11, -11, -9, -39, 24, -7, -32, -28, 8, 24, 14, 10, -16, 10, -32, 12, -10, -2, -1, -3, 9, 13, -2, 7, -21, 3, 9, -38, 6, 7, -42, 11, 17, -28, 28, 0, -25, 3, -4, -24, 4, 17, -7, 15, 7, -21, 10, -18, -13, 3, 5, 40, 5, 19, 9, 5, 20, -33, -25, -25, 9, -31, 37, -61, 2, 14, -16, -31, 24, -9, 13, -14, 18, 18, -36, -36, -18, -14, 4, 30, 14, -29, 39, -14, -24, 42, -6, -37, -17, 13, -12, -15, -3, -10, 5, -18, 12, 26, 11, -16, 14, 33, -4, 5, 10, 15, 15, -7, -18, 2, -33, -45, 4, 8, 20, -12, 41, 19, 34, -1, 7, 30, -9, 10, -1, -15, 34, 47, 6, 16, 14, -5, -13, 15, 20, -14, 20, -3, 15, -8, 6, 1, 32, -9, -26, 9, 15, -29, -49, -21, 24, 50, 0, -37, -4, -11, 23, -26, -5, 18, -15, 23, -5, -13, 6, -27, -7, -19, -16, -9, -23, 37, 13, 28, -26, -11, -1, 8, -8, 20, 0, -6, 23, 15, 15}

#define TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_27_GRU_CELL_27_BIAS_0 {-24, 46, -14, -70, -37, -28, -72, 21, -83, -48, -17, -72, 44, -6, 0, -17, -11, -21, 34, 0, 18, -2, 2, 10, 1, 10, -4, 3, 3, 4, 8, 4, -1, 1, 10, -7, -24, 46, -14, -70, -37, -28, -72, 21, -83, -48, -17, -72, 44, -6, 0, -17, -11, -21, 34, 0, 18, -2, 2, 10, -5, 0, -3, 3, -11, 14, 2, 1, 13, -7, 8, 16}

#define TENSOR_GRU_27_GRU_CELL_27_BIAS_0_DEC_BITS {6}

#define GRU_27_BIAS_LSHIFT {5}

#define GRU_27_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_28_GRU_CELL_28_KERNEL_0 {0, 19, 18, -48, 1, 12, 0, 0, -9, 30, 11, -14, -24, 6, 8, -26, 14, 23, -27, -6, -25, 25, 5, -31, 10, -35, -25, -18, -4, -19, -13, -12, 16, -39, 14, 40, 21, 3, -39, 9, -9, 44, 9, -42, -1, -11, -15, -26, 8, -24, -7, 6, 29, -18, 18, -3, -22, 11, 20, 43, 2, -17, -19, 41, 0, -40, 7, 20, 12, -2, -6, 30, -3, 41, -9, -8, -1, 17, 28, -14, 1, 42, -28, -34, 0, 34, 10, -29, -14, -8, 18, -8, -15, 2, 4, 10, -8, -5, 17, -2, -18, 28, -21, -25, 22, 15, -27, 1, -25, -11, -2, 50, 38, 11, 36, -13, 1, 10, -26, -17, 20, 9, -8, -5, 19, 9, 4, 15, -7, -12, -12, 80, 17, -10, 21, -29, -8, 4, 4, -6, 11, -17, 21, 24, 30, -7, -1, -20, 3, 14, 9, 0, 16, 26, -5, 18, 18, -60, -17, 8, 22, 19, 2, -20, 3, -5, 25, -3, 26, 32, 5, -12, 6, -11, 29, -15, 15, 45, -2, 11, 6, 66, -3, -35, -14, -1, -15, -3, 34, -17, -20, 17, -7, 8, 5, -7, -22, -12, 11, 6, 16, -3, 2, 2, 7, -11, -11, -10, -8, 4, 19, 1, -6, -2, 15, 0, 19, 11, -8, -10, 10, 12, 16, 5, 12, 45, -1, -10, -6, 4, -2, 20, 11, -23, 2, 14, 24, 12, -12, 5, -5, -30, 15, 2, -4, 12, -1, -9, -6, 14, 0, 29, 18, 4, 13, 6, -6, -18, -1, 3, -1, -8, -1, 4, 7, 21, 7, -13, 7, -15, -13, -2, 27, 31, 2, -13, 8, -48, -2, -7, -4, 1, 8, 0, -6, 11, 2, 0}

#define TENSOR_GRU_28_GRU_CELL_28_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0 {5, 15, 6, 33, 74, 40, -17, 28, 4, 4, -5, -14, -21, -4, -13, -5, 17, -1, 6, 1, 59, 11, 7, 20, 1, 64, 14, 34, 16, -8, 43, 41, 10, -6, -26, -34, 8, 28, 36, 28, -2, 72, 19, 22, 33, -4, 27, 42, 37, 14, -32, -7, 33, 32, 2, -1, 10, 6, 12, -31, -7, 41, -22, 61, 62, 19, 4, -6, -63, -22, 3, 71, 4, -13, -20, 0, 27, -94, -15, -27, -2, -13, 50, 26, 34, 35, -8, -4, -4, -26, 3, 24, -13, -31, 19, 36, -61, 15, 19, -2, 47, 23, -1, -20, -31, 4, -35, -27, 3, 23, 31, 0, 38, 3, -8, 16, 0, -8, 34, 44, -41, 7, 2, -16, -12, -11, -2, -10, 17, -10, 13, 21, 11, 7, 6, -5, 4, 24, 19, -10, 60, 2, -1, 37, -4, -15, 41, -28, 21, 0, 23, -7, -28, 29, -4, -4, -4, -11, -17, -4, -6, -5, 22, -32, 32, -5, -44, 57, -6, 27, -11, 26, 33, -31, 34, -5, 36, -20, 11, 15, 12, -9, 33, -2, -16, -19, 6, -6, 50, 9, -33, 2}

#define TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_28_GRU_CELL_28_BIAS_0 {50, 61, 87, 33, 72, -28, 48, 58, -16, -3, -75, -7, 1, -63, 6, -7, 13, 2, -12, 13, 6, 0, -15, 2, 50, 61, 87, 33, 72, -28, 48, 58, -16, -3, -75, -7, 1, -63, 6, -7, 25, 3, 13, 31, 14, -16, 8, 10}

#define TENSOR_GRU_28_GRU_CELL_28_BIAS_0_DEC_BITS {6}

#define GRU_28_BIAS_LSHIFT {5}

#define GRU_28_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_29_GRU_CELL_29_KERNEL_0 {68, 81, 55, -19, 29, 25, -2, -33, 2, -24, 26, 1, -5, -18, 51, 7, 22, 72, 3, -11, 13, 15, 12, -5, -7, -43, 30, -29, 32, -9, 7, -3, 85, 44, 31, 10, -24, -3, 14, -23, -12, -25, -52, 43, -46, -8, -27, 26, 19, 22, -25, -19, -18, -126, -52, 27, -89, -7, -19, 32, 15, 31, 11, -1, 37, -23, 43, 4, 20, -6, -9, -16, 21, 30, -34, -11, 43, -17, -33, 0, -20, 15, -2, -20, 10, -9, -14, -17, -16, -47, 35, 66, -28, -6, -41, -18, -9, -9, -32, 2, 56, 2, 14, 22, -11, -5, -15, 14, 21, -4, 32, 31, -30, 46, 35, 12, -4, -23, 20, -5, 5, -15, -45, -2, -22, -32, 4, 26, 9, 2, 53, -2, -2, 6, -28, -5, -14, -21, 54, 12, 16, 7, 18, -32}

#define TENSOR_GRU_29_GRU_CELL_29_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0 {-27, 48, 11, 41, -26, -33, 10, 11, 16, -27, -29, 14, -41, -20, -18, 6, -51, 67, -20, -6, -3, -18, 13, 31, -24, -72, -57, -25, -10, -8, 18, -6, -47, -47, -42, -30, 16, -25, 19, -16, -33, 4, -33, 4, 51, 18, 7, 2, 32, -21, -45, -11, 30, -31, 2, -13, 0, 13, -31, 22, -4, -59, -10, -2, -40, 0, -5, -34, 20, -45, -1, -34, 11, 57, -29, -19, 15, -17, 19, 19, -35, 26, -15, -16, 33, 40, -20, 2, -27, -3, -22, 25, 22, -3, 23, -2, 38, 7, 20, 13, -34, 8, -4, 14, 20, 41, -46, -41}

#define TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_29_GRU_CELL_29_BIAS_0 {77, 68, 88, 39, 127, 32, 25, -11, -23, -49, -4, -12, -1, -8, -8, -34, -1, -12, 77, 68, 88, 39, 127, 32, 25, -11, -23, -49, -4, -12, 7, -15, 18, -11, 0, -20}

#define TENSOR_GRU_29_GRU_CELL_29_BIAS_0_DEC_BITS {6}

#define GRU_29_BIAS_LSHIFT {6}

#define GRU_29_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_9_KERNEL_0 {30, -21, -25, -44, -8, -24, -5, -3, -47, 8, -15, -39, 15, 1, 17, 25, -13, 5, -36, 15, -19, -7, 0, 22, 64, -3, 13, -14, 15, 20, 10, -12, 38, 5, 15, -24}

#define TENSOR_DENSE_9_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_9_BIAS_0 {16, -48, -27, -59, -48, 67}

#define TENSOR_DENSE_9_BIAS_0_DEC_BITS {7}

#define DENSE_9_BIAS_LSHIFT {4}

#define DENSE_9_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define GRU_27_INPUT_OUTPUT_DEC 7
#define GRU_27_INPUT_OUTPUT_OFFSET 0
#define GRU_27_OUTPUT_DEC 7
#define GRU_27_OUTPUT_OFFSET 0
#define GRU_28_OUTPUT_DEC 7
#define GRU_28_OUTPUT_OFFSET 0
#define GRU_29_OUTPUT_DEC 7
#define GRU_29_OUTPUT_OFFSET 0
#define DENSE_9_OUTPUT_DEC 3
#define DENSE_9_OUTPUT_OFFSET 0
#define SOFTMAX_9_OUTPUT_DEC 7
#define SOFTMAX_9_OUTPUT_OFFSET 0

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

const nnom_io_config_t gru_27_input_config = {
    .super = {.name = "gru_27_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_27_gru_cell_27_kernel_0_data[] = TENSOR_GRU_27_GRU_CELL_27_KERNEL_0;

const nnom_shape_data_t tensor_gru_27_gru_cell_27_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_kernel_0_dec[] = TENSOR_GRU_27_GRU_CELL_27_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_27_gru_cell_27_kernel_0 = {
    .p_data = (void*)tensor_gru_27_gru_cell_27_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_27_gru_cell_27_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_27_gru_cell_27_recurrent_kernel_0_data[] = TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_27_gru_cell_27_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_recurrent_kernel_0_dec[] = TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_27_gru_cell_27_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_27_gru_cell_27_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_27_gru_cell_27_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_27_gru_cell_27_bias_0_data[] = TENSOR_GRU_27_GRU_CELL_27_BIAS_0;

const nnom_shape_data_t tensor_gru_27_gru_cell_27_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_bias_0_dec[] = TENSOR_GRU_27_GRU_CELL_27_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_27_gru_cell_27_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_27_gru_cell_27_bias_0 = {
    .p_data = (void*)tensor_gru_27_gru_cell_27_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_27_gru_cell_27_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_27_gru_cell_27_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_27_gru_cell_config = {
    .super = {.name = "gru_27"},
    .weights = (nnom_tensor_t*)&tensor_gru_27_gru_cell_27_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_27_gru_cell_27_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_27_gru_cell_27_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_27_config = {
    .super = {.name = "gru_27"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_28_gru_cell_28_kernel_0_data[] = TENSOR_GRU_28_GRU_CELL_28_KERNEL_0;

const nnom_shape_data_t tensor_gru_28_gru_cell_28_kernel_0_dim[] = {12, 24};
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_kernel_0_dec[] = TENSOR_GRU_28_GRU_CELL_28_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_28_gru_cell_28_kernel_0 = {
    .p_data = (void*)tensor_gru_28_gru_cell_28_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_28_gru_cell_28_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_28_gru_cell_28_recurrent_kernel_0_data[] = TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_28_gru_cell_28_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_recurrent_kernel_0_dec[] = TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_28_gru_cell_28_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_28_gru_cell_28_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_28_gru_cell_28_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_28_gru_cell_28_bias_0_data[] = TENSOR_GRU_28_GRU_CELL_28_BIAS_0;

const nnom_shape_data_t tensor_gru_28_gru_cell_28_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_bias_0_dec[] = TENSOR_GRU_28_GRU_CELL_28_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_28_gru_cell_28_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_28_gru_cell_28_bias_0 = {
    .p_data = (void*)tensor_gru_28_gru_cell_28_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_28_gru_cell_28_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_28_gru_cell_28_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_28_gru_cell_config = {
    .super = {.name = "gru_28"},
    .weights = (nnom_tensor_t*)&tensor_gru_28_gru_cell_28_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_28_gru_cell_28_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_28_gru_cell_28_bias_0,
    .q_dec_z = 2,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_28_config = {
    .super = {.name = "gru_28"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_29_gru_cell_29_kernel_0_data[] = TENSOR_GRU_29_GRU_CELL_29_KERNEL_0;

const nnom_shape_data_t tensor_gru_29_gru_cell_29_kernel_0_dim[] = {8, 18};
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_kernel_0_dec[] = TENSOR_GRU_29_GRU_CELL_29_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_29_gru_cell_29_kernel_0 = {
    .p_data = (void*)tensor_gru_29_gru_cell_29_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_29_gru_cell_29_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_29_gru_cell_29_recurrent_kernel_0_data[] = TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_29_gru_cell_29_recurrent_kernel_0_dim[] = {6, 18};
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_recurrent_kernel_0_dec[] = TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_29_gru_cell_29_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_29_gru_cell_29_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_29_gru_cell_29_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_29_gru_cell_29_bias_0_data[] = TENSOR_GRU_29_GRU_CELL_29_BIAS_0;

const nnom_shape_data_t tensor_gru_29_gru_cell_29_bias_0_dim[] = {2, 18};
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_bias_0_dec[] = TENSOR_GRU_29_GRU_CELL_29_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_29_gru_cell_29_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_29_gru_cell_29_bias_0 = {
    .p_data = (void*)tensor_gru_29_gru_cell_29_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_29_gru_cell_29_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_29_gru_cell_29_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_29_gru_cell_config = {
    .super = {.name = "gru_29"},
    .weights = (nnom_tensor_t*)&tensor_gru_29_gru_cell_29_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_29_gru_cell_29_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_29_gru_cell_29_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 6
};

const nnom_rnn_config_t gru_29_config = {
    .super = {.name = "gru_29"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_9_kernel_0_data[] = TENSOR_DENSE_9_KERNEL_0;

const nnom_shape_data_t tensor_dense_9_kernel_0_dim[] = {6, 6};
const nnom_qformat_param_t tensor_dense_9_kernel_0_dec[] = TENSOR_DENSE_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_kernel_0 = {
    .p_data = (void*)tensor_dense_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_9_bias_0_data[] = TENSOR_DENSE_9_BIAS_0;

const nnom_shape_data_t tensor_dense_9_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_9_bias_0_dec[] = TENSOR_DENSE_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_bias_0 = {
    .p_data = (void*)tensor_dense_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_9_output_shift[] = DENSE_9_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_9_bias_shift[] = DENSE_9_BIAS_LSHIFT;
const nnom_dense_config_t dense_9_config = {
    .super = {.name = "dense_9"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_9_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_9_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_9_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_9_bias_shift
};

const nnom_softmax_config_t softmax_9_config = {
    .super = {.name = "softmax_9"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_9_OUTPUT_DEC};
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

	layer[0] = input_s(&gru_27_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_27_gru_cell_config), &gru_27_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_28_gru_cell_config), &gru_28_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_29_gru_cell_config), &gru_29_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_9_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_9_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_GRU_NNOM_H