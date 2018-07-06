#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
typedef unsigned long long int lli;
using namespace std;

class job_events
{
public:
    lli timespamp;
    string missing_info;
    lli job_ID;
    string event_type;
    string user_name;
    string scheduling_class;
    string job_name;
    string logical_job_name;
    lli size=0;    
    job_events();
    bool insert(lli,string,lli,string,string,string,string,string);
    bool delet(string);
    bool update(lli,string,lli,string,string,string,string,string);
    string select(string);
};


class machine_attributes
{
public:
    lli timestamp;
    lli machine_ID;
    string attribute_name;
    string attribute_value;
    bool attribute_deleted;
    lli size=0;  
    machine_attributes();
    bool insert(lli,lli,string,string,bool);
    bool delet(lli);
    bool update(lli,lli,string,string,bool);
    string select(lli);


};

class machine_events
{
public:
    
    lli timestamp;
    lli machine_ID;
    string event_type;
    string platform_ID;
    string capacity_CPU;
    string capacity_memory;
    lli size=0;  
    machine_events();
    bool insert(lli,lli,string,string ,string,string);
    bool delet(lli);
    bool update(lli,lli,string,string ,string,string);
    string select(lli);

};
class task_constraints
{
public:
    
    lli timestamp;
    lli job_ID;
    lli task_index;
    string attribute_name;
    char comparison_operator;
    string attribute_value;
    lli size=0;  
    task_constraints();
    bool insert(lli,lli,lli,string,char,string);
    bool delet(lli);
    bool update(lli,lli,lli,string,char,string);
    string select(lli);

};

class task_events
{
public:
    
    lli timestamp;
    string missing_info;
    lli job_ID;
    string task_index;
    lli machine_ID;
    string event_type;
    string user_name;
    string scheduling_class;
    lli priority;
    string resource_request_for_CPU_cores;
    string resource_request_for_RAM;
    string resource_request_for_local_disk_space;
    string different_machine_constraint;    
    lli size=0;  
    task_events();
    bool insert(lli,string,lli,string,lli,string,string,string,lli,string,string,string,string);
    bool delet(string);
    bool update(lli,string,lli,string,lli,string,string,string,lli,string,string,string,string);
    string select(string);

};

struct task_usage{
	lli start_time;
	lli end_time;
	lli job_id;
	string task_index;
	lli machine_id;
	lli mean_cpu_usage_rate;
	lli canocical_memory_usage;
	lli assigned_memory_usage;
	lli unmapped_page_cache_memory_usage;
	lli total_page_cache_memory_usage;
	lli maximum_memory_usage;
	lli mean_disk_io_time;
	lli mean_local_disk_space_used;
	lli maximum_cpu_usage;
	lli maximum_disk_io_time;
	lli cycles_per_instruction_cpi;
	lli memory_acceses_per_instruccion_mai;
	lli sample_portion;
	lli aggregation_type;
	lli sampled_cpu_usage;
	lli size=0;
	task_usage();
	bool insert(lli,lli,lli,string,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli);
	bool delet(lli);
	bool update(lli,lli,lli,string,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli,lli);
	string select(lli);

};



















/*

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
};*/
