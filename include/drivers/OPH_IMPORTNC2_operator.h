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

#ifndef __OPH_IMPORTNC2_OPERATOR_H
#define __OPH_IMPORTNC2_OPERATOR_H

//Operator specific headers
#include "oph_common.h"
#include "oph_ophidiadb_main.h"
#include "oph_nc_library.h"
#include "oph_ioserver_library.h"

#define OPH_IMPORTNC2_SUBSET_INDEX	"index" 
#define OPH_IMPORTNC2_SUBSET_COORD	"coord"
#define OPH_IMPORTNC2_DIMENSION_DEFAULT	"auto"

//Only import of measured variables is supported

/**
 * \brief Structure of parameters needed by the operator OPH_IMPORTNC2. It creates a new datacube filling it with data taken from nc file
 *
 * \param oDB Contains the parameters and the connection to OphidiaDB
 * \param container_input Name of the input container used
 * \param create_container Flag indicating if the container has to be created
 * \param cwd Absolute path where the container is
 * \param run Simulate the run of operator to compute distribution parameters
 * \param nc_file_path Path of the nc file to import
 * \param partition_input Name of the host partition used to store data
 * \param grid_name Name of the grid used to specify dimensions
 * \param fs_type Type of file system used
 * \param ioserver_type Type of I/O server used
 * \param id_output_datacube ID of the output datacube created
 * \param id_input_container ID of the output container used/created
 * \param import_metadata Flag to indicate if metadata has to be imported with data
 * \param check_compliance Flag to indicate if compliance with reference vocabulary has to be checked
 * \param schedule_algo Number of the distribution algorithm to use
 * \param fragment_number Number of fragments that a process has to manage
 * \param fragment_id_start_position First fragment in the relative index set to work on
 * \param host_number Number of host to work on
 * \param dbmsxhost_number Number of dbms to use fo creation
 * \param dbxdbms_number Number of databases to create for each dbms
 * \param fragxdb_number Number of fragments for each database (upper bound)
 * \param tuplexfrag_number Number of tuples for each fragment (upper bound)
 * \param array_length Number of elements to store into a row
 * \param user Name of the user calling the import operation
 * \param measure Measure name
 * \param measure_type Type of data for the given measure
 * \param objkeys OPH_JSON objkeys to be included in output JSON file.
 * \param objkeys_num Number of objkeys.
 * \param server Pointer to I/O server handler
 * \param sessionid SessionID
 * \param id_vocabulary ID of the vocabulary used for metadata
 * \param id_dimension_hierarchy Array of id concept hierarchies of dimensions
 * \param base_time Base time in case of time dimension
 * \param units Units of dimension time
 * \param calendar Calendar associated to a time dimension
 * \param month_lengths Month lengths of each year
 * \param leap_year Value of the first leap year
 * \param leap_month Value of the leap month
 */
struct _OPH_IMPORTNC2_operator_handle
{
  ophidiadb oDB;
  char *container_input;
  int create_container;
  char *cwd;
  int run;
  char *nc_file_path;
  char *partition_input;
  char *grid_name;
  int fs_type;
  char *ioserver_type;
  int id_output_datacube;
  int id_input_container;
  int import_metadata;
  int check_compliance;
  int schedule_algo;
  int fragment_number;
  int fragment_first_id;
  int host_number;
  int dbmsxhost_number;
  int dbxdbms_number;
  int fragxdb_number;
  int tuplexfrag_number;
  int array_length;
  int total_frag_number;
  char *user;
  int ncid;
  NETCDF_var measure;
  int compressed;
  char **objkeys;
  int objkeys_num;
  oph_ioserver_handler *server;
  char *sessionid;
  int id_vocabulary;
  int *id_dimension_hierarchy;
  char* base_time;
  char* units;
  char* calendar;
  char* month_lengths;
  int leap_year;
  int leap_month;
};
typedef struct _OPH_IMPORTNC2_operator_handle OPH_IMPORTNC2_operator_handle;

#endif  //__OPH_IMPORTNC2_OPERATOR_H

