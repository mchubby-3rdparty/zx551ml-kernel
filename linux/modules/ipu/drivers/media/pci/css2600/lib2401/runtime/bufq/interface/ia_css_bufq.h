/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef _IA_CSS_BUFQ_H
#define _IA_CSS_BUFQ_H

#include <type_support.h>
#include "ia_css_bufq_comm.h"
#include "ia_css_buffer.h"
#include "ia_css_err.h"
#define BUFQ_EVENT_SIZE 4


/**
 * @brief Query the internal frame ID.
 *
 * @param[in]	key	The query key.
 * @param[out]	val	The query value.
 *
 * @return
 *	true, if the query succeeds;
 *	false, if the query fails.
 */
bool ia_css_query_internal_queue_id(
	enum ia_css_buffer_type buf_type,
	unsigned int thread_id,
	enum sh_css_queue_id *val
	);


/**
 * @brief  Map buffer type to a internal queue id.
 *
 * @param[in] thread id		Thread in which the buffer type has to be mapped or unmapped
 * @param[in] buf_type		buffer type.
 * @param[in] map		boolean flag to specify map or unmap
 * @return none
 */
void ia_css_queue_map(
	unsigned int thread_id,
	enum ia_css_buffer_type buf_type,
	bool map
	);


/**
 * @brief  Initilize buffer type to a queue id mapping
 * @return none
 */
void ia_css_queue_map_init(void);


/**
 * @brief initializes bufq module
 * It create instances of
 * -host to SP buffer queue  which is a list with predefined size,
 *	MxN queues where M is the number threads and N is the number queues per thread
 *-SP to host buffer queue , is a list with N queues
 *-host to SP event communication queue
 * -SP to host event communication queue
 * -queue for tagger commands
 * @return none
 */
void ia_css_bufq_init(void);


/**
* @brief Enqueues an item into host to SP buffer queue
 *
 * @param thread_index[in]	Thread in which the item to be enqueued
 *
 * @param queue_id[in]		Index of the queue in the specified thread
 * @param item[in]		Object to enqueue.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum ia_css_err ia_css_bufq_enqueue_buffer(
	int thread_index,
	int queue_id,
	uint32_t item);

/**
* @brief Dequeues an item from SP to host buffer queue.
 *
 * @param queue_id[in]		Specifies  the index of the queue in the list where
 *				the item has to be read.
 * @paramitem [out]		Object to be dequeued into this item.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum  ia_css_err ia_css_bufq_dequeue_buffer(
	int queue_id,
	uint32_t *item);

/**
* @brief  Enqueue an event item into host to SP communication event queue.
 *
 * @param[in]	evt_id		      The event ID.
 * @param[in]	evt_payload_0	The event payload.
 * @param[in]	evt_payload_1	The event payload.
 * @param[in]	evt_payload_2	The event payload.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum ia_css_err ia_css_bufq_enqueue_psys_event(
	uint8_t evt_id,
	uint8_t evt_payload_0,
	uint8_t evt_payload_1,
	uint8_t evt_payload_2
	);

/**
 * @brief   Dequeue an item from  SP to host communication event queue.
 *
 * @param item	Object to be dequeued into this item.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum  ia_css_err ia_css_bufq_dequeue_psys_event(
	uint8_t item[BUFQ_EVENT_SIZE]
	);

/**
 * @brief  Enqueue an event item into host to SP EOF event queue.
 *
 * @param[in]	evt_id		      The event ID.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
 */
enum ia_css_err ia_css_bufq_enqueue_isys_event(
	uint8_t evt_id);

/**
* @brief   Dequeue an item from  SP to host communication EOF event queue.

 *
 * @param item	Object to be dequeued into this item.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
 */
enum  ia_css_err ia_css_bufq_dequeue_isys_event(
	uint8_t item[BUFQ_EVENT_SIZE]);

/**
* @brief   Enqueue a tagger command item into tagger command queue..
 *
 * @param item	Object to be enqueue.
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum ia_css_err ia_css_bufq_enqueue_tag_cmd(
	uint32_t item);

/**
 * @brief   Enqueue a Unlock Raw buffer message into the queue..
 *
 * @param exp_id	Exposure ID - which uniquely identifies a raw buffer
 * @return		IA_CSS_SUCCESS or error code upon error.
 *
 */
enum ia_css_err ia_css_bufq_enqueue_unlock_raw_buff_msg(
	uint32_t exp_id);


/**
* @brief  Uninitializes bufq module.
 *
 * @return	IA_CSS_SUCCESS or error code upon error.
 *
*/
enum ia_css_err ia_css_bufq_deinit(void);


#endif	/* _IA_CSS_BUFQ_H */
