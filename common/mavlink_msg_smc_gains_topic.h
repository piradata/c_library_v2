#pragma once
// MESSAGE SMC_GAINS_TOPIC PACKING

#define MAVLINK_MSG_ID_SMC_GAINS_TOPIC 970606


typedef struct __mavlink_smc_gains_topic_t {
 uint64_t timestamp; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float k_gains[3]; /*<  gain for parameter K*/
 float beta_gains[3]; /*<  gain for parameter B*/
 float lambda_gains[3]; /*<  gain for parameter L*/
} mavlink_smc_gains_topic_t;

#define MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN 44
#define MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN 44
#define MAVLINK_MSG_ID_970606_LEN 44
#define MAVLINK_MSG_ID_970606_MIN_LEN 44

#define MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC 89
#define MAVLINK_MSG_ID_970606_CRC 89

#define MAVLINK_MSG_SMC_GAINS_TOPIC_FIELD_K_GAINS_LEN 3
#define MAVLINK_MSG_SMC_GAINS_TOPIC_FIELD_BETA_GAINS_LEN 3
#define MAVLINK_MSG_SMC_GAINS_TOPIC_FIELD_LAMBDA_GAINS_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SMC_GAINS_TOPIC { \
    970606, \
    "SMC_GAINS_TOPIC", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_smc_gains_topic_t, timestamp) }, \
         { "k_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_smc_gains_topic_t, k_gains) }, \
         { "beta_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_smc_gains_topic_t, beta_gains) }, \
         { "lambda_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_smc_gains_topic_t, lambda_gains) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SMC_GAINS_TOPIC { \
    "SMC_GAINS_TOPIC", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_smc_gains_topic_t, timestamp) }, \
         { "k_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_smc_gains_topic_t, k_gains) }, \
         { "beta_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_smc_gains_topic_t, beta_gains) }, \
         { "lambda_gains", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_smc_gains_topic_t, lambda_gains) }, \
         } \
}
#endif

/**
 * @brief Pack a smc_gains_topic message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param k_gains  gain for parameter K
 * @param beta_gains  gain for parameter B
 * @param lambda_gains  gain for parameter L
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_smc_gains_topic_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const float *k_gains, const float *beta_gains, const float *lambda_gains)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, k_gains, 3);
    _mav_put_float_array(buf, 20, beta_gains, 3);
    _mav_put_float_array(buf, 32, lambda_gains, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN);
#else
    mavlink_smc_gains_topic_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.k_gains, k_gains, sizeof(float)*3);
    mav_array_memcpy(packet.beta_gains, beta_gains, sizeof(float)*3);
    mav_array_memcpy(packet.lambda_gains, lambda_gains, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SMC_GAINS_TOPIC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
}

/**
 * @brief Pack a smc_gains_topic message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param k_gains  gain for parameter K
 * @param beta_gains  gain for parameter B
 * @param lambda_gains  gain for parameter L
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_smc_gains_topic_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const float *k_gains,const float *beta_gains,const float *lambda_gains)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, k_gains, 3);
    _mav_put_float_array(buf, 20, beta_gains, 3);
    _mav_put_float_array(buf, 32, lambda_gains, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN);
#else
    mavlink_smc_gains_topic_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.k_gains, k_gains, sizeof(float)*3);
    mav_array_memcpy(packet.beta_gains, beta_gains, sizeof(float)*3);
    mav_array_memcpy(packet.lambda_gains, lambda_gains, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SMC_GAINS_TOPIC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
}

/**
 * @brief Encode a smc_gains_topic struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param smc_gains_topic C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_smc_gains_topic_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_smc_gains_topic_t* smc_gains_topic)
{
    return mavlink_msg_smc_gains_topic_pack(system_id, component_id, msg, smc_gains_topic->timestamp, smc_gains_topic->k_gains, smc_gains_topic->beta_gains, smc_gains_topic->lambda_gains);
}

/**
 * @brief Encode a smc_gains_topic struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param smc_gains_topic C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_smc_gains_topic_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_smc_gains_topic_t* smc_gains_topic)
{
    return mavlink_msg_smc_gains_topic_pack_chan(system_id, component_id, chan, msg, smc_gains_topic->timestamp, smc_gains_topic->k_gains, smc_gains_topic->beta_gains, smc_gains_topic->lambda_gains);
}

/**
 * @brief Send a smc_gains_topic message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param k_gains  gain for parameter K
 * @param beta_gains  gain for parameter B
 * @param lambda_gains  gain for parameter L
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_smc_gains_topic_send(mavlink_channel_t chan, uint64_t timestamp, const float *k_gains, const float *beta_gains, const float *lambda_gains)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, k_gains, 3);
    _mav_put_float_array(buf, 20, beta_gains, 3);
    _mav_put_float_array(buf, 32, lambda_gains, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC, buf, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
#else
    mavlink_smc_gains_topic_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.k_gains, k_gains, sizeof(float)*3);
    mav_array_memcpy(packet.beta_gains, beta_gains, sizeof(float)*3);
    mav_array_memcpy(packet.lambda_gains, lambda_gains, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC, (const char *)&packet, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
#endif
}

/**
 * @brief Send a smc_gains_topic message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_smc_gains_topic_send_struct(mavlink_channel_t chan, const mavlink_smc_gains_topic_t* smc_gains_topic)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_smc_gains_topic_send(chan, smc_gains_topic->timestamp, smc_gains_topic->k_gains, smc_gains_topic->beta_gains, smc_gains_topic->lambda_gains);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC, (const char *)smc_gains_topic, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
#endif
}

#if MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_smc_gains_topic_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const float *k_gains, const float *beta_gains, const float *lambda_gains)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, k_gains, 3);
    _mav_put_float_array(buf, 20, beta_gains, 3);
    _mav_put_float_array(buf, 32, lambda_gains, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC, buf, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
#else
    mavlink_smc_gains_topic_t *packet = (mavlink_smc_gains_topic_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->k_gains, k_gains, sizeof(float)*3);
    mav_array_memcpy(packet->beta_gains, beta_gains, sizeof(float)*3);
    mav_array_memcpy(packet->lambda_gains, lambda_gains, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SMC_GAINS_TOPIC, (const char *)packet, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_MIN_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_CRC);
#endif
}
#endif

#endif

// MESSAGE SMC_GAINS_TOPIC UNPACKING


/**
 * @brief Get field timestamp from smc_gains_topic message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_smc_gains_topic_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field k_gains from smc_gains_topic message
 *
 * @return  gain for parameter K
 */
static inline uint16_t mavlink_msg_smc_gains_topic_get_k_gains(const mavlink_message_t* msg, float *k_gains)
{
    return _MAV_RETURN_float_array(msg, k_gains, 3,  8);
}

/**
 * @brief Get field beta_gains from smc_gains_topic message
 *
 * @return  gain for parameter B
 */
static inline uint16_t mavlink_msg_smc_gains_topic_get_beta_gains(const mavlink_message_t* msg, float *beta_gains)
{
    return _MAV_RETURN_float_array(msg, beta_gains, 3,  20);
}

/**
 * @brief Get field lambda_gains from smc_gains_topic message
 *
 * @return  gain for parameter L
 */
static inline uint16_t mavlink_msg_smc_gains_topic_get_lambda_gains(const mavlink_message_t* msg, float *lambda_gains)
{
    return _MAV_RETURN_float_array(msg, lambda_gains, 3,  32);
}

/**
 * @brief Decode a smc_gains_topic message into a struct
 *
 * @param msg The message to decode
 * @param smc_gains_topic C-struct to decode the message contents into
 */
static inline void mavlink_msg_smc_gains_topic_decode(const mavlink_message_t* msg, mavlink_smc_gains_topic_t* smc_gains_topic)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    smc_gains_topic->timestamp = mavlink_msg_smc_gains_topic_get_timestamp(msg);
    mavlink_msg_smc_gains_topic_get_k_gains(msg, smc_gains_topic->k_gains);
    mavlink_msg_smc_gains_topic_get_beta_gains(msg, smc_gains_topic->beta_gains);
    mavlink_msg_smc_gains_topic_get_lambda_gains(msg, smc_gains_topic->lambda_gains);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN? msg->len : MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN;
        memset(smc_gains_topic, 0, MAVLINK_MSG_ID_SMC_GAINS_TOPIC_LEN);
    memcpy(smc_gains_topic, _MAV_PAYLOAD(msg), len);
#endif
}
