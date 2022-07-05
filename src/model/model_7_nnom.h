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
#define TENSOR_GRU_18_GRU_CELL_18_KERNEL_0 {-71, 11, -55, 42, 31, -48, 6, -8, -26, 17, -28, 6, 17, 20, -14, -23, 4, -17, 39, 3, -13, 14, -28, 20, 32, 41, -43, 7, 40, 3, -13, 68, -10, -23, -37, 3, 41, 24, -21, 6, 60, 27, 63, -36, 8, -50, -10, 7, 1, 15, -22, -6, 2, 28, 62, 50, 14, -9, 46, -6, 5, -38, 17, -66, -47, 1, 4, 1, 28, 21, 4, 36, 43, 21, 34, -18, -23, -32, -24, 47, 11, 12, -3, 12, -16, -32, -19, 25, -35, -8, 11, -15, 4, 3, -4, -7, 31, 11, -21, 43, 37, 40, -37, 32, -3, -7, -7, -6}

#define TENSOR_GRU_18_GRU_CELL_18_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_18_GRU_CELL_18_RECURRENT_KERNEL_0 {52, -48, 25, -40, 13, -12, 85, 42, -3, 52, 11, 36, -47, -35, -3, -41, -44, 26, -9, -35, -37, 8, 23, -33, -16, -67, 9, -13, 8, -68, -27, 38, 6, -33, 42, -16, -20, 65, 19, 35, 22, 49, 45, -18, -36, 52, 39, -75, -18, 22, 44, 1, -35, 17, 28, -46, 3, -7, 6, 113, 29, -70, 2, -3, -43, 15, -24, 1, -2, -28, -14, 18, 54, 4, -24, -38, 12, 4, -20, -58, -18, -83, 48, 37, 35, -40, 0, -10, -11, -35, -17, 0, 14, 21, 9, 31, -11, -17, -13, 22, 37, 16, -14, -34, 30, -10, 4, -38, -21, -12, 58, -26, -8, 24, -38, -3, 11, -18, 42, 19, -16, -2, 4, 2, -7, -12, -40, 30, -19, 37, -9, -41, -54, -59, 51, 67, -9, 17, 41, -55, -13, 5, 6, 13, 29, 71, -7, 9, 22, 0, 21, -2, -27, -19, 20, 2, -30, 22, -27, -12, 37, 23, -2, -3, 15, 5, 30, 19, 43, 22, -19, -14, -28, -18, 41, 14, -35, -7, 3, 54, -23, -6, 3, -4, -5, -1, -6, 45, 17, -11, 25, 9, -30, -1, -12, 36, -13, -5, 5, 25, -28, 40, -4, -21, 51, -37, 20, 33, -19, -39, 18, 24, -5, -24, -29, -25, -28, 29, 5, 6, -28, -13, -13, 38, 0, -1, 36, -50, -40, 6, 53, 69, 12, -20, -19, 25, 41, -8, 12, 72, 23, 22, 16, -13, -38, -33, -12, -28, -5, -11, -18, -8, -10, 0, -14, 6, 11, -19, 29, -26, -45, 52, 0, 1, -23, -1, -23, -8, 17, 12, 3, 20, 1, 5, -18, 1, 17, -23, 36, -13, -4, -48, 34, -7, 22, -43, -59, -21, -1, 17, -24, 1, -17, 3, 5, 34, -2, 10, -8, 15, 40, -3, -6, 14, 39, -47, 15, -18, 19, 20, -36, -9, -4, -22, 7, 4, -11, -1, 37, -17, 5, -2, -6, 26, -8, 52, 12, -1, -1, 4, -79, 18, -6, 5, -27, 12, -18, 4, 31, -7, 14, -22, -19, -18, -15, 15, -15, -28, -20, -43, -14, 25, -6, -23, -15, 13, -9, -12, 58, -12, -9, 1, 0, 7, 20, 13, -26, 32, 17, -22, -32, -33, -40, 32, 12, -17, 10, 26, -28, 14, -4, 28, 15, -64, 1, -15, -2, -10, 4, 6, -56, -11, 5, -6, -3, -1, -2, 3, 31, -22, -48, 23, 27, 4, 17, 10, 4, -17, 37, -4, -11, -9, 19, 0, -19, 10, -3, -20, 5, 5, -38, 19, 13, -43, 1, 41, -5, -51, -17, 12, 14, 9}

#define TENSOR_GRU_18_GRU_CELL_18_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_18_GRU_CELL_18_BIAS_0 {7, -53, 43, 39, -74, -64, -42, -28, -66, 6, -2, -58, -2, 0, -12, -16, 10, -17, 4, 46, 13, -7, -4, -37, 1, -9, -3, 7, -4, -2, 1, -3, -3, 12, 5, 8, 7, -53, 43, 39, -74, -64, -42, -28, -66, 6, -2, -58, -2, 0, -12, -16, 10, -17, 4, 46, 13, -7, -4, -37, -17, 6, -8, -2, 8, -14, 24, -9, -4, 3, -1, -13}

#define TENSOR_GRU_18_GRU_CELL_18_BIAS_0_DEC_BITS {6}

#define GRU_18_BIAS_LSHIFT {5}

#define GRU_18_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_19_GRU_CELL_19_KERNEL_0 {13, 17, -13, 85, -68, 2, 61, 24, -49, 51, 17, -38, -27, 25, -20, -12, -62, -5, -3, -17, 32, 13, -128, -6, -35, 33, 7, 39, -37, 68, 38, -33, -30, 28, 72, -26, 48, -6, -72, -57, -48, -13, 66, -29, 42, 12, -43, -46, -72, 3, 34, -2, 1, -36, 52, 28, -6, -34, 8, -33, -5, -24, -20, 21, 66, -24, -85, 40, 67, 12, -49, 53, -15, 5, -27, -18, -108, 20, 73, 31, 9, -16, -1, -8, -105, 52, -12, 4, -10, -100, -1, 2, -29, 26, 88, -78, 18, 41, -16, -33, -28, 109, 10, -13, -91, 23, -64, 10, 38, -25, 19, -61, 41, -3, -69, 18, 10, 2, -41, 2, -4, 24, 40, -18, 16, 28, -60, 40, 9, -14, -32, -44, 23, 1, 44, -27, 1, -2, 11, 3, 30, -82, -3, 82, 6, -48, -8, 41, -37, 12, 10, 29, -48, -18, 3, -5, 9, -4, 36, -13, 4, 39, 28, -12, 6, -25, 19, 22, 52, -26, -72, 41, 1, -27, 32, -9, 11, 27, -17, 4, 59, 39, 33, 10, -15, 15, 27, -14, 38, -8, -7, 28, -10, -21, 23, 24, 13, -46, 11, 25, 42, 12, 35, -7, -14, 18, 21, 12, 10, -8, -23, 11, -17, -30, 18, -25}

#define TENSOR_GRU_19_GRU_CELL_19_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_19_GRU_CELL_19_RECURRENT_KERNEL_0 {113, 83, 88, -61, 50, 12, -36, -50, -42, -15, -13, -18, -63, 22, -27, -30, 39, -65, -37, 25, -2, 3, -117, 65, -32, 1, 60, -10, -56, 31, 5, 30, -9, -9, -55, -22, 71, -22, -7, -2, 35, 9, -33, -24, 93, 63, -8, -9, -35, 122, -14, -85, 17, 108, 5, -29, -22, -32, 38, -40, 8, -39, -2, 45, -11, 79, -16, 125, 30, 11, 7, 2, 90, 2, -57, 20, -63, -5, 33, -45, -86, -35, -19, -62, 24, -16, -23, 56, -29, 54, -5, -23, 2, -27, -3, 35, 64, -49, -46, -6, 9, 51, 28, -71, 37, 69, -20, 40}

#define TENSOR_GRU_19_GRU_CELL_19_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_19_GRU_CELL_19_BIAS_0 {86, 37, 56, 29, -20, 58, 5, -10, -22, 17, 30, 6, 20, 2, 7, -14, 14, -10, 86, 37, 56, 29, -20, 58, 5, -10, -22, 17, 30, 6, 3, 2, -13, -35, 16, -19}

#define TENSOR_GRU_19_GRU_CELL_19_BIAS_0_DEC_BITS {6}

#define GRU_19_BIAS_LSHIFT {6}

#define GRU_19_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_20_GRU_CELL_20_KERNEL_0 {17, -10, 66, 12, 24, 10, 31, 39, 16, 24, -19, -7, -11, -13, -14, -10, 34, 43, -35, -40, 7, -31, -34, -26, 7, -10, 28, 70, 4, 21, 20, -54, -24, -13, 5, -36, 14, 15, 8, 0, 63, -5, -42, -31, 5, 1, -21, 57, -18, 2, -36, 11, -34, -16, -15, 92, -10, -23, 33, -25, 51, 54, 4, -2, 53, -39, 19, -25, -3, -4, 47, -30, -18, 32, 70, -9, -16, -16, 9, -32, -5, -31, -14, -2, -4, -29, 21, -26, -11, -22, -28, -26, -49, -35, 15, -28, -48, 54, 36, -1, -25, -20, -16, -36, -1, 10, -9, 26}

#define TENSOR_GRU_20_GRU_CELL_20_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_20_GRU_CELL_20_RECURRENT_KERNEL_0 {-31, -42, 10, 1, 18, -25, 20, 6, -22, 6, -19, -11, 8, -20, -51, -32, -19, -14, 34, -6, -5, -52, 30, 13, -1, -26, 28, 4, -56, -27, 21, 3, -50, -33, -9, -2, -26, -31, 24, -27, -25, -14, 40, 12, -49, -32, -44, -3, -23, 39, -8, -16, 23, -13, -14, -47, -32, -16, 13, 56, 27, -10, -22, -43, -1, 14, -34, -19, -1, 11, 29, -57, 18, 0, -3, 33, -7, -35, -26, 17, -10, 23, -9, 17, 68, 3, 1, 9, -11, -4, -27, 18, 6, -33, 17, 3, -15, -13, -18, 26, 26, -21, 9, -18, 13, -54, 78, 24}

#define TENSOR_GRU_20_GRU_CELL_20_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_20_GRU_CELL_20_BIAS_0 {54, 77, 87, 50, 85, 27, -62, -5, -18, -8, 1, -2, 11, -22, 28, -12, -41, 21, 54, 77, 87, 50, 85, 27, -62, -5, -18, -8, 1, -2, 0, -24, 0, -6, -37, 17}

#define TENSOR_GRU_20_GRU_CELL_20_BIAS_0_DEC_BITS {6}

#define GRU_20_BIAS_LSHIFT {6}

#define GRU_20_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_6_KERNEL_0 {-28, -28, 71, -2, -16, 3, -30, -12, -1, 15, -2, -51, -6, -29, 24, 3, -12, 0, 13, -19, 5, 21, 3, -26, 4, -7, 59, 3, 47, -1, 34, 16, 9, 11, -6, -15}

#define TENSOR_DENSE_6_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_6_BIAS_0 {-38, -86, 11, -46, 39, 36}

#define TENSOR_DENSE_6_BIAS_0_DEC_BITS {7}

#define DENSE_6_BIAS_LSHIFT {4}

#define DENSE_6_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define GRU_18_INPUT_OUTPUT_DEC 7
#define GRU_18_INPUT_OUTPUT_OFFSET 0
#define GRU_18_OUTPUT_DEC 7
#define GRU_18_OUTPUT_OFFSET 0
#define GRU_19_OUTPUT_DEC 7
#define GRU_19_OUTPUT_OFFSET 0
#define GRU_20_OUTPUT_DEC 7
#define GRU_20_OUTPUT_OFFSET 0
#define DENSE_6_OUTPUT_DEC 4
#define DENSE_6_OUTPUT_OFFSET 0
#define SOFTMAX_6_OUTPUT_DEC 7
#define SOFTMAX_6_OUTPUT_OFFSET 0

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

const nnom_io_config_t gru_18_input_config = {
    .super = {.name = "gru_18_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_18_gru_cell_18_kernel_0_data[] = TENSOR_GRU_18_GRU_CELL_18_KERNEL_0;

const nnom_shape_data_t tensor_gru_18_gru_cell_18_kernel_0_dim[] = {3, 36};
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_kernel_0_dec[] = TENSOR_GRU_18_GRU_CELL_18_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_18_gru_cell_18_kernel_0 = {
    .p_data = (void*)tensor_gru_18_gru_cell_18_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_18_gru_cell_18_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_18_gru_cell_18_recurrent_kernel_0_data[] = TENSOR_GRU_18_GRU_CELL_18_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_18_gru_cell_18_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_recurrent_kernel_0_dec[] = TENSOR_GRU_18_GRU_CELL_18_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_18_gru_cell_18_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_18_gru_cell_18_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_18_gru_cell_18_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_18_gru_cell_18_bias_0_data[] = TENSOR_GRU_18_GRU_CELL_18_BIAS_0;

const nnom_shape_data_t tensor_gru_18_gru_cell_18_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_bias_0_dec[] = TENSOR_GRU_18_GRU_CELL_18_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_18_gru_cell_18_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_18_gru_cell_18_bias_0 = {
    .p_data = (void*)tensor_gru_18_gru_cell_18_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_18_gru_cell_18_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_18_gru_cell_18_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_18_gru_cell_config = {
    .super = {.name = "gru_18"},
    .weights = (nnom_tensor_t*)&tensor_gru_18_gru_cell_18_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_18_gru_cell_18_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_18_gru_cell_18_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_18_config = {
    .super = {.name = "gru_18"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_19_gru_cell_19_kernel_0_data[] = TENSOR_GRU_19_GRU_CELL_19_KERNEL_0;

const nnom_shape_data_t tensor_gru_19_gru_cell_19_kernel_0_dim[] = {12, 18};
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_kernel_0_dec[] = TENSOR_GRU_19_GRU_CELL_19_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_19_gru_cell_19_kernel_0 = {
    .p_data = (void*)tensor_gru_19_gru_cell_19_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_19_gru_cell_19_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_19_gru_cell_19_recurrent_kernel_0_data[] = TENSOR_GRU_19_GRU_CELL_19_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_19_gru_cell_19_recurrent_kernel_0_dim[] = {6, 18};
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_recurrent_kernel_0_dec[] = TENSOR_GRU_19_GRU_CELL_19_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_19_gru_cell_19_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_19_gru_cell_19_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_19_gru_cell_19_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_19_gru_cell_19_bias_0_data[] = TENSOR_GRU_19_GRU_CELL_19_BIAS_0;

const nnom_shape_data_t tensor_gru_19_gru_cell_19_bias_0_dim[] = {2, 18};
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_bias_0_dec[] = TENSOR_GRU_19_GRU_CELL_19_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_19_gru_cell_19_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_19_gru_cell_19_bias_0 = {
    .p_data = (void*)tensor_gru_19_gru_cell_19_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_19_gru_cell_19_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_19_gru_cell_19_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_19_gru_cell_config = {
    .super = {.name = "gru_19"},
    .weights = (nnom_tensor_t*)&tensor_gru_19_gru_cell_19_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_19_gru_cell_19_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_19_gru_cell_19_bias_0,
    .q_dec_z = 2,
    .q_dec_h = 7,
    .units = 6
};

const nnom_rnn_config_t gru_19_config = {
    .super = {.name = "gru_19"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_20_gru_cell_20_kernel_0_data[] = TENSOR_GRU_20_GRU_CELL_20_KERNEL_0;

const nnom_shape_data_t tensor_gru_20_gru_cell_20_kernel_0_dim[] = {6, 18};
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_kernel_0_dec[] = TENSOR_GRU_20_GRU_CELL_20_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_20_gru_cell_20_kernel_0 = {
    .p_data = (void*)tensor_gru_20_gru_cell_20_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_20_gru_cell_20_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_20_gru_cell_20_recurrent_kernel_0_data[] = TENSOR_GRU_20_GRU_CELL_20_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_20_gru_cell_20_recurrent_kernel_0_dim[] = {6, 18};
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_recurrent_kernel_0_dec[] = TENSOR_GRU_20_GRU_CELL_20_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_20_gru_cell_20_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_20_gru_cell_20_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_20_gru_cell_20_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_20_gru_cell_20_bias_0_data[] = TENSOR_GRU_20_GRU_CELL_20_BIAS_0;

const nnom_shape_data_t tensor_gru_20_gru_cell_20_bias_0_dim[] = {2, 18};
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_bias_0_dec[] = TENSOR_GRU_20_GRU_CELL_20_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_20_gru_cell_20_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_20_gru_cell_20_bias_0 = {
    .p_data = (void*)tensor_gru_20_gru_cell_20_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_20_gru_cell_20_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_20_gru_cell_20_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_20_gru_cell_config = {
    .super = {.name = "gru_20"},
    .weights = (nnom_tensor_t*)&tensor_gru_20_gru_cell_20_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_20_gru_cell_20_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_20_gru_cell_20_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .units = 6
};

const nnom_rnn_config_t gru_20_config = {
    .super = {.name = "gru_20"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_6_kernel_0_data[] = TENSOR_DENSE_6_KERNEL_0;

const nnom_shape_data_t tensor_dense_6_kernel_0_dim[] = {6, 6};
const nnom_qformat_param_t tensor_dense_6_kernel_0_dec[] = TENSOR_DENSE_6_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_6_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_6_kernel_0 = {
    .p_data = (void*)tensor_dense_6_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_6_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_6_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_6_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_6_bias_0_data[] = TENSOR_DENSE_6_BIAS_0;

const nnom_shape_data_t tensor_dense_6_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_6_bias_0_dec[] = TENSOR_DENSE_6_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_6_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_6_bias_0 = {
    .p_data = (void*)tensor_dense_6_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_6_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_6_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_6_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_6_output_shift[] = DENSE_6_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_6_bias_shift[] = DENSE_6_BIAS_LSHIFT;
const nnom_dense_config_t dense_6_config = {
    .super = {.name = "dense_6"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_6_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_6_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_6_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_6_bias_shift
};

const nnom_softmax_config_t softmax_6_config = {
    .super = {.name = "softmax_6"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_6_OUTPUT_DEC};
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

	layer[0] = input_s(&gru_18_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_18_gru_cell_config), &gru_18_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_19_gru_cell_config), &gru_19_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_20_gru_cell_config), &gru_20_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_6_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_6_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_GRU_NNOM_H