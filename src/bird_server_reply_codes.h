#ifndef BIRD_CLIENT__BIRD_SERVER_REPLY_CODES_H
#define BIRD_CLIENT__BIRD_SERVER_REPLY_CODES_H

//=============================================================================
// The reply codes in this file are from BIRD routing daemon documentation:
// https://github.com/CZ-NIC/bird/blob/master/doc/reply_codes
//=============================================================================

// 0xxx	Action suceessfully completed
// 1xxx	Table entry
// 2xxx	Table heading
// 8xxx	Run-time error
// 9xxx	Parse-time error

// 0000	OK
// 0001	Welcome
// 0002	Reading configuration
// 0003	Reconfigured
// 0004	Reconfiguration in progress
// 0005	Reconfiguration already in progress, queueing
// 0006	Reconfiguration ignored, shutting down
// 0007	Shutdown ordered
// 0008	Already disabled
// 0009	Disabled
// 0010	Already enabled
// 0011	Enabled
// 0012	Restarted
// 0013	Status report
// 0014	Route count
// 0015	Reloading
// 0016	Access restricted
// 0017	Reconfiguration already in progress, removing queued config
// 0018	Reconfiguration confirmed
// 0019	Nothing to do (configure undo/confirm)
// 0020	Configuration OK
// 0021	Undo requested
// 0022	Undo scheduled
// 0023	Evaluation of expression
// 0024	Graceful restart status report
// 0025	Graceful restart ordered

// 1000	BIRD version
// 1001	Interface list
// 1002	Protocol list
// 1003	Interface address
// 1004	Interface flags
// 1005	Interface summary
// 1006	Protocol details
// 1007	Route list
// 1008	Route details
// 1009	Static route list
// 1010	Symbol list
// 1011	Uptime
// 1012	Route extended attribute list
// 1013	Show ospf neighbors
// 1014	Show ospf
// 1015	Show ospf interface
// 1016	Show ospf state/topology
// 1017	Show ospf lsadb
// 1018	Show memory
// 1019	Show ROA list
// 1020	Show BFD sessions
// 1021	Show RIP interface
// 1022	Show RIP neighbors
// 1023	Show Babel interfaces
// 1024	Show Babel neighbors
// 1025	Show Babel entries

// 8000	Reply too long
// 8001	Route not found
// 8002	Configuration file error
// 8003	No protocols match
// 8004	Stopped due to reconfiguration
// 8005	Protocol is down => cannot dump
// 8006	Reload failed
// 8007	Access denied
// 8008	Evaluation runtime error

// 9000	Command too long
// 9001	Parse error
// 9002	Invalid symbol type

#define OK                                          "0000"
#define WELCOME                                     "0001"
#define READING_CONFIGURATION                       "0002"
#define RECONFIGURED                                "0003"
#define RECONFIGURED_IN_PROGRESS                    "0004"
#define RECONFIGURED_ALREADY_IN_PROGR_QUEUEING      "0005"
#define RECONFIGURED_IGNORED                        "0006"
#define SHUTDOWN_ORDERED                            "0007"
#define ALREADY_DISABLED                            "0008"
#define DISABLED                                    "0009"
#define ALREADY_ENABLED                             "0010"
#define ENABLED                                     "0011"
#define RESTARTED                                   "0012"
#define STATUS_REPORT                               "0013"
#define ROUTE_COUNT                                 "0014"
#define RELOADING                                   "0015"
#define ACCESS_RESTRICTED                           "0016"
#define RECONFIGURATION_ALREADY_IN_PROGR_REMOVING   "0017"
#define RECONFIGURATION_CONFIRMED                   "0018"
#define NOTHING_TO_DO                               "0019"
#define CONFIGURATION_OK                            "0020"
#define UNDO_REQUESTED                              "0021"
#define UNDO_SCHEDULED                              "0022"
#define EVALUATION_OF_EXPRESSION                    "0023"
#define GRACEFUL_RESTART_STATUS_REPORT              "0024"
#define GRACEFUL_RESTART_ORDERED                    "0025"

#define BIRD_VERSION                                "1000"
#define INTERFACE_LIST                              "1001"
#define PROTOCOL_LIST                               "1002"
#define INTERFACE_ADDRESS                           "1003"
#define INTERFACE_FLAGS                             "1004"
#define INTERFACE_SUMMARY                           "1005"
#define PROTOCOL_DETAILS                            "1006"
#define ROUTE_LIST                                  "1007"
#define ROUTE_DETAILS                               "1008"
#define STATIC_ROUTE_LIST                           "1009"
#define SYMBOL_LIST                                 "1010"
#define UPTIME                                      "1011"
#define ROUTE_EXTENDED_ATTRIBUTE_LIST               "1012"
#define SHOW_OSPF_NEIGHBORS                         "1013"
#define SHOW_OSPF                                   "1014"
#define SHOW_OSPF_INTERFACE                         "1015"
#define SHOW_OSPF_STATE_TOPOLOGY                    "1016"
#define SHOW_OSPF_LSADB                             "1017"
#define SHOW_MEMORY                                 "1018"
#define SHOW_ROA_LIST                               "1019"
#define SHOW_BFD_SESSIONS                           "1020"
#define SHOW_RIP_INTERFACE                          "1021"
#define SHOW_RIP_NEIGHBORS                          "1022"
#define SHOW_BABEL_INTERFACES                       "1023"
#define SHOW_BABEL_NEIGHBORS                        "1024"
#define SHOW_BABEL_ENTRIES                          "1025"

#define REPLY_TOO_LONG                              "8000"
#define ROUTE_NOT_FOUND                             "8001"
#define CONFIGURATION_FILE_ERROR                    "8002"
#define NO_PROTOCOLS_MATCH                          "8003"
#define STOPPED_DUE_TO_RECONFIGURATION              "8004"
#define PROTOCOL_IS_DOWN_CANNOT_DUMP                "8005"
#define RELOAD_FAILED                               "8006"
#define ACCESS_DENIED                               "8007"
#define EVALUATION_RUNTIME_ERROR                    "8008"

#define COMMAND_TOO_LONG                            "9000"
#define PARSE_ERROR                                 "9001"
#define INVALID_SYMBOL_TYPE                         "9002"

#endif // BIRD_CLIENT__BIRD_SERVER_REPLY_CODES_H
