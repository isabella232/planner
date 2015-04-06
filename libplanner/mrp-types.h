/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2001-2003 CodeFactory AB
 * Copyright (C) 2001-2003 Richard Hult <richard@imendio.com>
 * Copyright (C) 2001-2002 Mikael Hallendal <micke@imendio.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __MRP_TYPES_H__
#define __MRP_TYPES_H__

#include <libplanner/mrp-time.h>

#define MRP_TYPE_RELATION_TYPE (mrp_relation_type_get_type ())
#define MRP_TYPE_TASK_TYPE     (mrp_task_type_get_type ())
#define MRP_TYPE_TASK_SCHED    (mrp_task_sched_get_type ())
#define MRP_TYPE_PROPERTY_TYPE (mrp_property_type_get_type ())
#define MRP_TYPE_STRING_LIST   (mrp_string_list_get_type ())

/**
 * MrpRelationType:
 * @MRP_RELATION_NONE: invalid relation type (unset)
 * @MRP_RELATION_FS: finish to start
 * @MRP_RELATION_FF: finish to finish (unimplemented)
 * @MRP_RELATION_SS: start to start (unimplemented)
 * @MRP_RELATION_SF: start to finish (unimplemented)
 *
 * The type of relation.
 */
typedef enum {
	MRP_RELATION_NONE = 0, /* unset */
	MRP_RELATION_FS,       /* finish-to-start */
	MRP_RELATION_FF,       /* finish-to-finish */
	MRP_RELATION_SS,       /* start-to-start */
	MRP_RELATION_SF        /* start-to-finish */
} MrpRelationType;

/**
 * MrpConstraintType:
 * @MRP_CONSTRAINT_ASAP: as soon as possible
 * @MRP_CONSTRAINT_ALAP: as late as possible (unimplemented)
 * @MRP_CONSTRAINT_SNET: start no eariler than
 * @MRP_CONSTRAINT_FNLT: finish no later than (unimplemented)
 * @MRP_CONSTRAINT_MSO: must start on
 *
 * The type of constraint for the task. The default is %MRP_CONSTRAINT_ASAP.
 */
typedef enum {
	MRP_CONSTRAINT_ASAP = 0, /* as-soon-as-possible */
	MRP_CONSTRAINT_ALAP,     /* as-late-as-possible */
	MRP_CONSTRAINT_SNET,     /* start-no-earlier-than */
	MRP_CONSTRAINT_FNLT,     /* finish-no-later-than */
	MRP_CONSTRAINT_MSO,      /* must-start-on */
} MrpConstraintType;

struct _MrpConstraint {
	MrpConstraintType type;
	mrptime           time;
};

typedef enum {
	MRP_TASK_TYPE_NORMAL,
	MRP_TASK_TYPE_MILESTONE
} MrpTaskType;

typedef enum {
	MRP_TASK_SCHED_FIXED_WORK,
	MRP_TASK_SCHED_FIXED_DURATION
} MrpTaskSched;


/**
 * MrpTask:
 *
 * Object representing a task in the project.
 */
typedef struct _MrpTask       MrpTask;
/**
 * MrpResource:
 *
 * Object representing a task in the project.
 */
typedef struct _MrpResource   MrpResource;
/**
 * MrpGroup:
 *
 * Object representing a resource group.
 */
typedef struct _MrpGroup      MrpGroup;
/**
 * MrpAssignment:
 *
 * Represents an assignment, i.e. the assignment of a task to a resource.
 */
typedef struct _MrpAssignment MrpAssignment;
/**
 * MrpConstraint:
 * @type:
 * @time:
 *
 * A struct representing a scheduling constraint on a task.
 */
typedef struct _MrpConstraint MrpConstraint;

GType   mrp_relation_type_get_type (void) G_GNUC_CONST;

GType   mrp_task_type_get_type     (void) G_GNUC_CONST;

GType   mrp_task_sched_get_type    (void) G_GNUC_CONST;

GType   mrp_property_type_get_type (void) G_GNUC_CONST;

GList * mrp_string_list_copy       (const GList *list);

void    mrp_string_list_free       (GList       *list);

#endif /* __MRP_TYPES_H__ */
