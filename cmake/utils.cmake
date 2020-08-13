# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

function(get_target_tree output_variable)
  if(${ARGC} LESS 1)
    message(FATAL_ERROR "Usage: get_target_tree output_var target1 target2 ...")
  endif()
  
  foreach(target ${ARGN})
    list(APPEND queue "${target}")
  endforeach()

  while(true)
    # Update the queue
    unset(new_queue)
    
    foreach(target ${queue})
      list(APPEND visited_dependencies "${target}")
      
      if (NOT TARGET "${target}")
        continue()
      endif()
      
      # Always reset to empty value
      set(target_link_libs "target_link_libs-NOTFOUND")
      set(target_interface_link_libs "target_interface_link_libs-NOTFOUND")

      # Skip utility targets
      get_target_property(target_type "${target}" TYPE)
      if("${target_type}" STREQUAL "UTILITY")
        continue()
      endif()

      # We can only get LINK_LIBRARIES from normal targets
      if(NOT "${target_type}" STREQUAL "INTERFACE_LIBRARY")
        get_target_property(target_link_libs "${target}" LINK_LIBRARIES)
      else()
        set(target_link_libs "target_link_libs-NOTFOUND")
      endif()

      # INTERFACE_LINK_LIBRARIES are potentially always present
      get_target_property(target_interface_link_libs "${target}" INTERFACE_LINK_LIBRARIES)

      # Collect the results
      unset(new_queue_candidates)

      if(NOT "${target_link_libs}" STREQUAL "target_link_libs-NOTFOUND")
        list(APPEND new_queue_candidates ${target_link_libs})
      endif()

      if(NOT "${target_interface_link_libs}" STREQUAL "target_interface_link_libs-NOTFOUND")
        list(APPEND new_queue_candidates ${target_interface_link_libs})
      endif()

      foreach(queue_candidate ${new_queue_candidates})
        list(FIND visited_dependencies "${queue_candidate}" visited)
        if(visited EQUAL -1)
          list(APPEND new_queue "${queue_candidate}")
        endif()
      endforeach()
    endforeach()

    list(LENGTH new_queue new_queue_size)
    if(${new_queue_size} EQUAL 0)
      break()
    endif()

    set(queue ${new_queue})
  endwhile()

  set("${output_variable}" ${visited_dependencies} PARENT_SCOPE)
endfunction()

function(get_public_include_folders output_variable)
  if(${ARGC} LESS 1)
    message(FATAL_ERROR "Usage: get_public_include_folders output_var target1 target2 ...")
  endif()
  
  foreach(target ${ARGN})
    if (NOT TARGET "${target}")
      continue()
    endif()
    
    get_target_property(include_dir_list "${target}" INTERFACE_INCLUDE_DIRECTORIES)
    if(NOT "${include_dir_list}" STREQUAL "include_dir_list-NOTFOUND")
      list(APPEND collected_include_dirs "${include_dir_list}")
    endif()
  endforeach()

  set("${output_variable}" ${collected_include_dirs} PARENT_SCOPE)
endfunction()
