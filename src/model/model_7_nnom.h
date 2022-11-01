#ifndef MODEL_7_NNOM_H
#define MODEL_7_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_7_nnom
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
#define TENSOR_GRU_27_GRU_CELL_27_KERNEL_0 {-36, 29, -28, 18, 14, -21, -2, -1, 5, 2, 1, 3, -26, 59, -23, -7, 27, -28, 18, -48, 31, 0, -8, 71, 74, -24, 13, -29, -23, -14, -1, -27, -8, -31, -37, -56, -8, 15, 48, -72, -27, 34, -24, 7, -38, 0, 3, 81, -36, -20, -14, 16, -38, 14, 13, -31, -15, -37, 5, 44, 19, -11, -22, 7, -8, 18, 18, -9, -32, 19, -11, -39, -41, 39, -43, 51, 27, 32, -24, -23, -10, 4, -2, -31, 14, -39, 46, 39, -23, -5, 31, -25, 7, -15, -6, -33, -18, -13, -24, 25, 17, 18, 5, -9, 11, 7, -10, -47}

#define TENSOR_GRU_27_GRU_CELL_27_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0 {-26, 41, 49, -56, 38, -14, 22, -29, 22, 24, 13, 15, -13, 20, -30, 36, 65, -66, 35, -38, -13, 28, 5, 16, 24, -40, -38, 41, 55, -1, 14, 52, -20, 18, 28, -40, 28, -7, 51, -15, 65, -41, 0, 24, -18, -40, -44, 44, -23, -7, 50, -17, 5, 59, 9, 34, 38, -34, -26, -18, -50, 43, 12, 6, 52, -8, -26, 45, 29, 8, -18, -1, 90, 47, -68, -6, 14, 25, -21, -26, -31, -31, -38, 13, -56, -54, -6, 49, 56, 48, -4, -33, -26, -6, -10, -25, 70, 81, 17, -23, 19, -28, -23, -32, -8, -11, -24, 51, -8, -6, -3, 37, -42, -39, 31, -66, 46, 6, -17, -30, 35, -36, -38, 35, 32, -14, -1, 17, 0, 43, 63, -13, 13, 41, -37, -34, 41, -33, -81, 14, -19, -32, -1, 31, -26, 3, -11, 10, 16, 19, -31, 10, -44, 31, 33, 17, 25, -27, 16, -9, 41, -13, 8, -2, -21, 15, -15, -7, 0, -27, -2, 7, 0, -25, -2, 18, -24, 13, -24, 9, 20, -28, -18, 27, 8, 7, -20, 22, -8, -31, -14, 49, -23, -13, -27, -15, 7, 26, -10, 39, 7, 18, -19, 3, -4, 2, -102, -7, -20, -9, -8, -41, -53, 4, 21, -9, -22, -35, -16, 44, 23, 3, 1, -31, -63, 25, 14, -23, -20, -15, 18, -3, 26, 9, 28, 7, 54, 40, -39, -21, -43, -27, 7, -13, -19, -19, 56, 6, -1, -67, 24, -84, -5, -55, -10, -39, -32, 31, 23, -2, 17, 55, -23, 39, 17, -4, -23, -46, -11, -35, -13, 16, 3, -15, 8, 2, -15, -13, 31, 23, 26, 23, 62, 4, 54, 33, -2, 6, 16, 12, 11, 12, -6, -20, 1, 11, 22, -11, -14, -9, 7, -13, 16, -26, 2, -19, -23, -40, -6, 8, -23, 41, 0, -28, -35, 40, 7, 17, -20, -10, -3, 12, -2, -3, -24, -19, -24, 42, 12, -8, -14, 0, -21, 1, -18, -26, -2, -14, 1, -2, 25, 12, 2, -48, 4, 10, -11, 18, -10, -8, -22, -8, 15, -21, 11, -3, 12, -16, -23, 14, -1, -5, 22, -12, 19, -25, 13, 3, -39, 8, 25, -18, 7, 12, 9, 13, 19, -9, -3, 5, 17, 26, -4, -39, 13, 18, 23, -31, -2, -8, 30, -14, 25, 2, 9, -25, 36, -6, 4, -3, 22, -46, -25, 8, -24, -17, -35, -14, -28, 12, 36, 3, -24, 7, -9, 20, -5, 24, 1, 5, -12, -32, -20, 45, -2, 1, 3, -10, 19, 4, 12, 14}

#define TENSOR_GRU_27_GRU_CELL_27_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_27_GRU_CELL_27_BIAS_0 {25, -16, -46, -73, -49, 0, -25, -45, -58, -77, -28, -10, -18, -1, -16, 9, 14, -32, 21, 32, -1, -5, 16, -23, 6, 5, -2, 4, -6, -5, 1, -5, 3, 7, -1, -9, 25, -16, -46, -73, -49, 0, -25, -45, -58, -77, -28, -10, -18, -1, -16, 9, 14, -32, 21, 32, -1, -5, 16, -23, -1, 9, 2, -15, 9, -1, -14, 10, -8, -11, -4, -7}

#define TENSOR_GRU_27_GRU_CELL_27_BIAS_0_DEC_BITS {6}

#define GRU_27_BIAS_LSHIFT {7}

#define GRU_27_OUTPUT_RSHIFT {6}

#define TENSOR_GRU_28_GRU_CELL_28_KERNEL_0 {-10, -14, -22, -11, -11, -34, 22, -2, -39, 26, -19, 40, 24, 21, 22, -17, 2, 17, 11, -55, -1, 3, 9, -86, 46, 24, 24, -7, -23, -54, 10, -2, -21, -40, 59, -31, 30, -2, -19, -40, 17, -1, 31, 16, -32, 34, 29, -16, -18, -12, -59, 34, -32, 45, -44, 31, -116, -35, -31, -50, -120, 37, -48, -3, 46, 19, 85, 61, 50, -38, 64, -19, 31, 51, -33, -66, 82, -20, 59, -26, -43, -80, 44, 70, -90, -33, 72, 8, -5, 30, -69, -45, 85, 19, -1, 17, 30, -26, 18, -3, 21, 58, -15, 74, 34, -17, 0, -14, -8, -40, 55, -24, -44, -90, -49, -49, -54, -50, -24, -51, 3, -44, -1, 11, 6, 57, 47, 11, 9, 0, -22, 34, 18, 17, 17, 0, 9, -2, -45, 5, -37, 51, 10, -7, 10, 37, 25, 18, -7, -6, -15, -19, 5, 10, -49, 3, 5, 18, 32, -16, -5, -20, 17, -21, -24, -49, 6, 5, 9, -25, 36, 13, 5, -34, -38, 13, 8, 3, 39, -11, -34, -19, 13, 14, 47, -2, -20, 12, -28, 27, 33, 0, 7, -12, 31, -15, -2, -19, -21, -33, 27, -31, 11, 33, -32, -30, 9, 32, 39, 20, -6, -13, -2, -11, -38, 46}

#define TENSOR_GRU_28_GRU_CELL_28_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0 {-57, -7, 28, 4, -31, -21, -44, -35, -11, -20, 48, -7, -35, 44, 5, -45, 11, 22, 38, -1, 5, 1, 34, -25, -31, -2, 37, -33, 65, -4, 3, 47, -10, 18, 14, 35, 13, 36, 18, 33, -2, -1, 21, -7, 20, -12, -6, -31, 11, -22, 75, 9, -27, -14, -1, 15, 7, 12, 23, 7, 17, 6, -12, -2, -22, 1, -11, -25, 21, -10, 8, -15, 20, -34, 31, 0, 10, -20, 7, 45, -15, -40, 76, -20, 32, -4, -13, 33, 14, 33, -18, 1, -18, 19, -37, -5, 14, -35, 27, 5, 35, 17, 22, -15, 13, -35, -11, 8}

#define TENSOR_GRU_28_GRU_CELL_28_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_28_GRU_CELL_28_BIAS_0 {78, -66, -23, -69, 36, 57, -9, 16, 33, -12, 19, -9, -3, 10, -3, 27, 0, 4, 78, -66, -23, -69, 36, 57, -9, 16, 33, -12, 19, -9, 0, 13, -10, 32, 2, 3}

#define TENSOR_GRU_28_GRU_CELL_28_BIAS_0_DEC_BITS {6}

#define GRU_28_BIAS_LSHIFT {6}

#define GRU_28_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_29_GRU_CELL_29_KERNEL_0 {23, 8, 1, 12, 0, -19, 13, -18, -5, 20, 57, 51, -5, 10, 4, -4, -15, 19, 1, -7, -14, -20, -24, -54, 13, -35, 10, -21, -4, -76, -7, -25, -5, 17, -6, 76, -3, 5, 46, -65, -22, 5, -36, -61, -48, 13, -26, 38, -10, -2, -6, 54, -5, -17, -26, 7, -62, -105, -1, -13, 4, 12, -5, 8, -62, -5, 67, 9, 2, -37, 8, -52, -20, -7, 36, -51, -23, 11, -10, -63, -1, 12, 10, 27, -6, 48, -22, -19, -47, -18, -1, 22, 16, -19, -32, 0, -45, 0, -22, 45, 28, 22, 5, 2, 33, 15, -21, -54}

#define TENSOR_GRU_29_GRU_CELL_29_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0 {11, -10, -17, -2, -19, -31, 11, 23, 25, -21, -20, -12, 12, -23, -22, -33, 17, 24, -27, 9, 9, 23, 4, 3, 44, -2, -30, -7, 5, 83, -4, -6, -59, -7, -51, -19, 5, 24, -11, -9, 13, 16, 40, -34, 19, 20, 43, -7, -9, 21, 9, 9, -35, 12, 37, 1, -37, -8, -5, 1, -32, -12, 31, -6, 36, -2, -26, 3, -49, 17, 6, 7, 37, -23, -8, 35, -23, 34, 14, -10, -3, -14, 0, -1, 19, -30, 2, 29, 21, 8, -19, -3, -17, 8, -9, 23, -16, 16, 51, -79, 20, -3, 8, -13, -25, 0, 31, 12}

#define TENSOR_GRU_29_GRU_CELL_29_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_29_GRU_CELL_29_BIAS_0 {79, 79, 70, 86, 53, 74, 14, -15, -17, -8, 18, 17, -9, -10, -4, 1, 27, 23, 79, 79, 70, 86, 53, 74, 14, -15, -17, -8, 18, 17, -5, -12, -31, -11, 16, 16}

#define TENSOR_GRU_29_GRU_CELL_29_BIAS_0_DEC_BITS {6}

#define GRU_29_BIAS_LSHIFT {6}

#define GRU_29_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_9_KERNEL_0 {-16, -47, -16, 67, -8, 49, -32, 35, 50, 83, 102, -75, -50, -43, -30, -40, 55, -21, -1, -4, -30, -3, -42, 18, -26, 24, -4, 78, -55, 38, 57, 21, -80, 44, 27, 49}

#define TENSOR_DENSE_9_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_9_BIAS_0 {-94, 20, -8, -72, -17, 48}

#define TENSOR_DENSE_9_BIAS_0_DEC_BITS {8}

#define DENSE_9_BIAS_LSHIFT {4}

#define DENSE_9_OUTPUT_RSHIFT {9}


/* output q format for each layer */
#define GRU_27_INPUT_OUTPUT_DEC 9
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

const nnom_shape_data_t tensor_gru_28_gru_cell_28_kernel_0_dim[] = {12, 18};
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

const nnom_shape_data_t tensor_gru_28_gru_cell_28_recurrent_kernel_0_dim[] = {6, 18};
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

const nnom_shape_data_t tensor_gru_28_gru_cell_28_bias_0_dim[] = {2, 18};
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
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 6
};

const nnom_rnn_config_t gru_28_config = {
    .super = {.name = "gru_28"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_29_gru_cell_29_kernel_0_data[] = TENSOR_GRU_29_GRU_CELL_29_KERNEL_0;

const nnom_shape_data_t tensor_gru_29_gru_cell_29_kernel_0_dim[] = {6, 18};
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
    .q_dec_z = 4,
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

#endif //MODEL_7_NNOM_H