#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <class tt>
struct machine_atributtes{
	tt timestamp;
	tt machine_id;
	tt attribute_name;
	tt attribute_value;
	bool attribute_deleted;
};
template <class tt>
struct machine_evets{
	tt timestamp;
	tt machine_id;
	tt event_type;
	tt plataform_id;
	tt capacity_cpu;
	tt capacity_memory;
};
template <class tt>
struct job_events{
	tt timestamp;
	tt missing_info;
	tt job_id;
	tt event_type;
	tt user_name;
	tt scheduling_class;
	tt job_name;
	tt logical_job_name;
};
template <class tt>
struct tast_events{
	tt timestamp;
	tt missing_info;
	tt job_id;
	tt task_index;
	tt machine_id;
	tt event_type;
	tt user_name;
	tt scheduling_class;
	tt priority;
	tt request_cpu;
	tt request_ram;
	tt request_disk;
	tt different_machine;
};

template <class tt>
struct task_contrains{
	tt timestamp;
	tt job_id;
	tt task_index;
	tt attribute_name;
	tt attribute_value;
	tt comparison_operator;
};

template <class tt>
struct task_usage{
	tt start_time;
	tt end_time;
	tt job_id;
	tt task_index;
	tt machine_id;
	tt mean_cpu_usage_rate;
	tt canocical_memory_usage;
	tt assigned_memory_usage;
	tt unmapped_page_cache_memory_usage;
	tt total_page_cache_memory_usage;
	tt maximum_memory_usage;
	tt mean_disk_io_time;
	tt mean_local_disk_space_used;
	tt maximum_cpu_usage;
	tt maximum_disk_io_time;
	tt cycles_per_instruction_cpi;
	tt memory_acceses_per_instruccion_mai;
	tt sample_portion;
	tt aggregation_type;
	tt sampled_cpu_usage;
};
