/*
    Ophidia Analytics Framework
    Copyright (C) 2012-2016 CMCC Foundation

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OPH_DATACUBE_QUERY_H__
#define __OPH_DATACUBE_QUERY_H__

#include "oph_ioserver/oph_ioserver_submission_query.h" 

#define OPH_DC_SQ_CREATE_DB  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_DB) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_DB, "%s")
#define OPH_DC_SQ_DROP_DB    OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_DROP_DB) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_DB, "%s")
#define OPH_DC_SQ_CREATE_FRAG  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_COLUMN_NAME, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_COLUMN_TYPE, "long|blob")

#define OPH_DC_SQ_INSERT_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "?|?")
#define OPH_DC_SQ_INSERT_COMPRESSED_FRAG  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "?|oph_compress('','',?)")

#define OPH_DC_SQ_INSERT_FRAG2 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "?|%s('oph_%s|oph_%s','oph_%s', ?, ?)")
#define OPH_DC_SQ_INSERT_COMPRESSED_FRAG2  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "?|oph_compress(%s('oph_%s|oph_%s','oph_%s', ?, ?))")

#define OPH_DC_SQ_MULTI_INSERT_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_MULTI_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FINAL_STATEMENT, OPH_IOSERVER_SQ_VAL_NO) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "")

#define OPH_DC_SQ_MULTI_INSERT_FRAG_FINAL OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_MULTI_INSERT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FINAL_STATEMENT, OPH_IOSERVER_SQ_VAL_YES) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|measure") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_VALUE, "")

#define OPH_DC_SQ_MULTI_INSERT_ROW "?|?|"
#define OPH_DC_SQ_MULTI_INSERT_COMPRESSED_ROW "?|oph_compress('','',?)|"


#define OPH_DC_SQ_GET_ID_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "%d|%d")

#define OPH_DC_SQ_READ_FRAG_SPECIAL1 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|%s|oph_dump('OPH_%s', 'OPH_%s', %s)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") "%s" OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER_DIR, "ASC") "%s" 

#define OPH_DC_SQ_READ_FRAG_SPECIAL2 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|oph_dump('OPH_%s', 'OPH_%s', %s)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") "%s" OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER_DIR, "ASC") "%s" 

#define OPH_DC_SQ_READ_FRAG_SPECIAL3 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|%s|oph_bit_dump('', '', %s)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") "%s" OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER_DIR, "ASC") "%s" 

#define OPH_DC_SQ_READ_FRAG_SPECIAL4 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|oph_bit_dump('', '', %s)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") "%s" OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER_DIR, "ASC") "%s" 

#define OPH_DC_SQ_READ_RAW_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_FUNCTION) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FUNC, "oph_export") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ARG, "%s")

#define OPH_DC_SQ_READ_RAW_COMPRESSED_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|oph_uncompress('','', measure)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") 

#define OPH_DC_SQ_READ_RAW_FRAG2 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") 

#define OPH_DC_SQ_READ_RAW_FRAG3 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim")

#define OPH_DC_SQ_READ_RAW_FRAG3_I OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") 

#define OPH_DC_SQ_READ_RAW_FRAG3_W OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s")  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") 

#define OPH_DC_SQ_READ_RAW_FRAG3_WI OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s")  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") 

#define OPH_DC_SQ_READ_RAW_FRAG3_L OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "%d") 

#define OPH_DC_SQ_READ_RAW_FRAG3_LI OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "%d") 

#define OPH_DC_SQ_READ_RAW_FRAG3_WL OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s")  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "%d")

#define OPH_DC_SQ_READ_RAW_FRAG3_WLI OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "id_dim|%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s")  OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ORDER, "id_dim") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "%d") 

#define OPH_DC_SQ_COUNT_ELEMENTS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_convert_l('OPH_LONG', '', oph_aggregate_operator('OPH_LONG', 'OPH_LONG', oph_value_to_bin('OPH_LONG', 'OPH_LONG', oph_count_array('OPH_%s', 'OPH_%s', measure)), 'OPH_SUM'))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") 

#define OPH_DC_SQ_COUNT_COMPRESSED_ELEMENTS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_convert_l('OPH_LONG', '', oph_aggregate_operator('OPH_LONG', 'OPH_LONG', oph_value_to_bin('OPH_LONG', 'OPH_LONG', oph_count_array( 'OPH_%s',  'OPH_%s', oph_uncompress('','',measure))), 'OPH_SUM'))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") 

#define OPH_DC_SQ_COUNT_ELEMENTS_FRAG_ROW OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_count_array('OPH_%s', 'OPH_%s', measure )") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "0|1") 
 
#define OPH_DC_SQ_COUNT_COMPRESSED_ELEMENTS_FRAG_ROW OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_count_array('OPH_%s', 'OPH_%s', oph_uncompress('','',measure))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "0|1") 

#define OPH_DC_SQ_COUNT_BIT_ELEMENTS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_convert_l('OPH_LONG', '', oph_aggregate_operator('OPH_LONG', 'OPH_LONG', oph_value_to_bin('OPH_LONG', 'OPH_LONG', oph_bit_size('', '', measure)), 'OPH_SUM'))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") 

#define OPH_DC_SQ_COUNT_COMPRESSED_BIT_ELEMENTS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_convert_l('OPH_LONG', '', oph_aggregate_operator('OPH_LONG', 'OPH_LONG', oph_value_to_bin('OPH_LONG', 'OPH_LONG', oph_bit_size('', '', oph_uncompress('','',measure))), 'OPH_SUM'))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") 

#define OPH_DC_SQ_COUNT_BIT_ELEMENTS_FRAG_ROW OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_bit_size('', '', measure)") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "0|1") 

#define OPH_DC_SQ_COUNT_COMPRESSED_BIT_ELEMENTS_FRAG_ROW OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_bit_size('', '', oph_uncompress('','', measure))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_LIMIT, "0|1") 

#define OPH_DC_SQ_DELETE_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_DROP_FRAG) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s")

#define OPH_DC_SQ_SIZE_ELEMENTS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_FUNCTION) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FUNC, "oph_size") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_ARG, "%s")

#define OPH_DC_SQ_RETRIEVE_PRIMITIVES_LIST OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, OPH_IOSERVER_SQ_KW_FUNCTION_FIELDS) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, OPH_IOSERVER_SQ_KW_FUNCTION_TABLE)

#define OPH_DC_SQ_RETRIEVE_PRIMITIVES_LIST_W OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, OPH_IOSERVER_SQ_KW_FUNCTION_FIELDS) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, OPH_IOSERVER_SQ_KW_FUNCTION_TABLE) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "name LIKE '%%%s%%'") 

#define OPH_DC_SQ_COUNT_ROWS_FRAG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_convert_l('OPH_LONG','',oph_aggregate_operator('OPH_LONG','OPH_LONG', oph_to_bin('OPH_LONG','OPH_LONG', '1'),'OPH_COUNT'))") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") 

#define OPH_DC_SQ_APPLY_PLUGIN OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s")
#define OPH_DC_SQ_APPLY_PLUGIN_W OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s")
#define OPH_DC_SQ_APPLY_PLUGIN_G OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "mysql.oph_id(%s,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "mysql.oph_id(%s,%lld)")
#define OPH_DC_SQ_APPLY_PLUGIN_WG OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "mysql.oph_id(%s,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "mysql.oph_id(%s,%lld)")

#define OPH_DC_SQ_APPLY_PLUGIN_GB OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_id2(%s,%lld,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "oph_id2(%s,%lld,%lld)")
#define OPH_DC_SQ_APPLY_PLUGIN_WGB OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_id2(%s,%lld,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "oph_id2(%s,%lld,%lld)")
#define OPH_DC_SQ_APPLY_PLUGIN_GB2 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_id3(%s,?,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "oph_id3(%s,?,%lld)")
#define OPH_DC_SQ_APPLY_PLUGIN_WGB2 OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_OPERATION, OPH_IOSERVER_SQ_OP_CREATE_FRAG_SELECT) OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FRAG, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD, "oph_id3(%s,?,%lld)|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FIELD_ALIAS, "%s|%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_FROM, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_WHERE, "%s") OPH_IOSERVER_SQ_BLOCK(OPH_IOSERVER_SQ_ARG_GROUP, "oph_id3(%s,?,%lld)")

#define MYSQL_DC_CREATE_DB "CREATE DATABASE IF NOT EXISTS %s DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci"
#define MYSQL_DC_DELETE_DB "DROP DATABASE IF EXISTS %s"
#define MYSQL_DC_CREATE_FRAG "CREATE TABLE %s (id_dim integer, measure longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1"

#define MYSQL_DC_INSERT_FRAG "INSERT INTO %s (id_dim, measure) VALUES (?, ?)"
#define MYSQL_DC_INSERT_COMPRESSED_FRAG "INSERT INTO %s (id_dim, measure) VALUES (?, oph_compress('','',?))"

#define MYSQL_DC_MULTI_INSERT_FRAG "INSERT INTO %s (id_dim, measure) VALUES (?, ?), (?, ?), ..."
#define MYSQL_DC_MULTI_INSERT_COMPRESSED_FRAG "INSERT INTO %s (id_dim, measure) VALUES (?, oph_compress('','',?)), (?, oph_compress('','',?)), ..."

#define MYSQL_DC_GET_ID_FRAG "SELECT id_dim FROM %s limit %d,%d"

#define MYSQL_DC_READ_FRAG_SPECIAL1 "SELECT %s, %s, oph_dump('OPH_%s','',%s) FROM %s %s ORDER BY %s ASC %s"
#define MYSQL_DC_READ_FRAG_SPECIAL2 "SELECT %s, oph_dump('OPH_%s','',%s) FROM %s %s ORDER BY %s ASC %s"
#define MYSQL_DC_READ_FRAG_SPECIAL3 "SELECT %s, %s, oph_bit_dump('','',%s) FROM %s %s ORDER BY %s ASC %s"
#define MYSQL_DC_READ_FRAG_SPECIAL4 "SELECT %s, oph_bit_dump('','',%s) FROM %s %s ORDER BY %s ASC %s"

#define MYSQL_DC_READ_RAW_FRAG "SELECT id_dim, measure FROM %s ORDER BY id_dim"

#define MYSQL_DC_READ_RAW_COMPRESSED_FRAG "SELECT id_dim, oph_uncompress('','',measure) FROM %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG2 "SELECT id_dim, %s FROM %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG3_I "SELECT id_dim, %s, %s FROM %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG3_WI "SELECT id_dim, %s, %s FROM %s WHERE %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG3_LI "SELECT id_dim, %s, %s FROM %s ORDER BY id_dim LIMIT %d"
#define MYSQL_DC_READ_RAW_FRAG3_WLI "SELECT id_dim, %s, %s FROM %s WHERE %s ORDER BY id_dim LIMIT %d"
#define MYSQL_DC_READ_RAW_FRAG3 "SELECT id_dim, %s FROM %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG3_W "SELECT id_dim, %s FROM %s WHERE %s ORDER BY id_dim"
#define MYSQL_DC_READ_RAW_FRAG3_L "SELECT id_dim, %s FROM %s ORDER BY id_dim LIMIT %d"
#define MYSQL_DC_READ_RAW_FRAG3_WL "SELECT id_dim, %s FROM %s WHERE %s ORDER BY id_dim LIMIT %d"

#define MYSQL_DC_COUNT_ELEMENTS_FRAG "SELECT oph_convert_l('OPH_LONG','',oph_aggregate_operator('OPH_LONG','OPH_LONG',oph_value_to_bin('','OPH_LONG',oph_count_array('OPH_%s','',measure)),'OPH_SUM')) FROM %s"
#define MYSQL_DC_COUNT_COMPRESSED_ELEMENTS_FRAG "SELECT oph_convert_l('OPH_LONG','',oph_aggregate_operator('OPH_LONG','OPH_LONG',oph_value_to_bin('','OPH_LONG',oph_count_array('OPH_%s','',oph_uncompress('','',measure))),'OPH_SUM')) FROM %s"
#define MYSQL_DC_COUNT_ELEMENTS_FRAG_ROW "SELECT oph_count_array('OPH_%s','',measure) FROM %s LIMIT 0,1"
#define MYSQL_DC_COUNT_COMPRESSED_ELEMENTS_FRAG_ROW "SELECT oph_count_array('OPH_%s','',oph_uncompress('','',measure)) FROM %s LIMIT 0,1"

#define MYSQL_DC_COUNT_BIT_ELEMENTS_FRAG "SELECT oph_convert_l('OPH_LONG','',oph_aggregate_operator('OPH_LONG','OPH_LONG',oph_value_to_bin('','OPH_LONG',oph_bit_size(measure)),'OPH_SUM')) FROM %s"
#define MYSQL_DC_COUNT_COMPRESSED_BIT_ELEMENTS_FRAG "SELECT oph_convert_l('','OPH_LONG',oph_aggregate_operator('OPH_LONG','OPH_LONG',oph_value_to_bin('','OPH_LONG',oph_bit_size('','',oph_uncompress('','',measure))),'OPH_SUM')) FROM %s"
#define MYSQL_DC_COUNT_BIT_ELEMENTS_FRAG_ROW "SELECT oph_bit_size('','',measure) FROM %s LIMIT 0,1"
#define MYSQL_DC_COUNT_COMPRESSED_BIT_ELEMENTS_FRAG_ROW "SELECT oph_bit_size('','',oph_uncompress('','',measure)) FROM %s LIMIT 0,1"

#define MYSQL_DC_APPLY_PLUGIN "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT %s, %s AS %s FROM %s"
#define MYSQL_DC_APPLY_PLUGIN_W "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT %s, %s AS %s FROM %s WHERE %s"

#define MYSQL_DC_APPLY_PLUGIN_G "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT mysql.oph_id(%s,%lld) AS %s, %s AS %s FROM %s GROUP BY mysql.oph_id(%s,%lld)"
#define MYSQL_DC_APPLY_PLUGIN_WG "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT mysql.oph_id(%s,%lld) AS %s, %s AS %s FROM %s WHERE %s GROUP BY mysql.oph_id(%s,%lld)"
#define MYSQL_DC_APPLY_PLUGIN_W_ID "SET @ID:=%lld-1; CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT @ID:=@ID+1 AS %s, %s AS %s FROM %s WHERE %s"
#define MYSQL_DC_APPLY_PLUGIN_GB "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT oph_id2(%s,%lld,%lld) AS %s, %s AS %s FROM %s GROUP BY oph_id2(%s,%lld,%lld)"
#define MYSQL_DC_APPLY_PLUGIN_WGB "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT oph_id2(%s,%lld,%lld) AS %s, %s AS %s FROM %s WHERE %s GROUP BY oph_id2(%s,%lld,%lld)"
#define MYSQL_DC_APPLY_PLUGIN_GB2 "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT oph_id3(%s,?,%lld) AS %s, %s AS %s FROM %s GROUP BY oph_id3(%s,?,%lld)"
#define MYSQL_DC_APPLY_PLUGIN_WGB2 "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT oph_id3(%s,?,%lld) AS %s, %s AS %s FROM %s WHERE %s GROUP BY oph_id3(%s,?,%lld)"

#define MYSQL_DC_SIZE_ELEMENTS_FRAG "SELECT oph_convert_l('','OPH_LONG',oph_aggregate_operator('OPH_LONG','OPH_LONG',oph_value_to_bin('','OPH_LONG',index_length+data_length),'OPH_SUM')) AS size FROM information_schema.TABLES WHERE table_name IN (%s);"

#define MYSQL_DC_DELETE_FRAG "DROP TABLE IF EXISTS %s"

#define MYSQL_DC_MAX_ROW_LENGTH_FRAG "SELECT MAX(LENGTH(measure)) FROM %s"

#define MYSQL_DC_APPLY_MYSQL_INTERCOMPARISON "CREATE TABLE %s (%s integer, %s longblob) ENGINE=MyISAM DEFAULT CHARSET=latin1 AS SELECT %s.%s AS %s, oph_sum_array('oph_%s|oph_%s','oph_%s',%s.%s,oph_mul_scalar('oph_%s','oph_%s',%s.%s,-1.0)) AS %s FROM %s, %s WHERE %s.%s = %s.%s"

#define MYSQL_QUERY_RETRIEVE_PRIMITIVES_LIST "SELECT name,ret,dl,type FROM mysql.func;"
#define MYSQL_QUERY_RETRIEVE_PRIMITIVES_LIST_W "SELECT name,ret,dl,type FROM mysql.func WHERE name LIKE '%%%s%%';"

#endif /* __OPH_DATACUBE_QUERY_H__ */
