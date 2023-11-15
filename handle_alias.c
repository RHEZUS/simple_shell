#include "main.h"

struct Alias aliases[MAX_ALIASES];

/* int alias_count = 0; move to main.h */

/**
 * handle_alias - this function is used to handle alias
 * @argv: list of alias
 */

int alias_count = 0;

void handle_alias(char **argv)
{
	int i;

	if (argv[1] == NULL)
		print_all_aliases();
	else
		for (i = 1; argv[i] != NULL; i++)
			if (_strchr(argv[i], '=') == NULL)
				print_alias(argv[i]);
			else
				create_update_alias(argv[i]);
}

/**
 * create_update_alias - this function is used to create or update an alias
 * @alias: the alias
 */
void create_update_alias(char *alias)
{
	char *name = _strtok(alias, "=");
	char *value = _strtok(NULL, "=");
	int exists = 0, i, j;
	/*printf("%s\n", name);*/

	for (j = 0; j < alias_count; j++)
	{
		if (_strcmp(value, aliases[j].name) == 0)
		{
			value = _strdup(aliases[j].value);
			break;
		}
	}

	for (i = 0; i < alias_count; i++)
	{
		/*printf("looping aliases: %s='%s'\n", aliases[i].name, aliases[i].value);*/
		if (_strcmp(name, aliases[i].name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = _strdup(value);
			exists = 1;
			/*printf("modified alias: %s='%s'\n", aliases[i].name, aliases[i].value);*/
			break;
		}
	}

	if (!exists)
	{

		aliases[alias_count].name = _strdup(name);
		aliases[alias_count].value = _strdup(value);
		/**
		 * printf("newly created: %s='%s'\n", aliases[alias_count].
		 * name, aliases[alias_count].value);
		 */
		alias_count++;
	}
}

/**
 * print_all_aliases - print all alias
 */
void print_all_aliases(void)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		/**
		 * write(1, aliases->name, sizeof(aliases->name));
		 * write(1, "='", 2);
		 * write(1, aliases->value, sizeof(aliases->value) - 1);
		 * write(1, "'\n", 2);
		 */
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * print_alias - print a single alias
 * @name: the alias
 */
void print_alias(char *name)
{
	int i, alias_found = 0;

	alias_found = 0;

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, name) == 0)
		{
			/**
			 * write(1, aliases->name, sizeof(aliases->name));
			 * write(1, "=", 1);
			 * write(1, aliases->value, sizeof(aliases->value));
			 * write(1, "\n", 1);
			 */

			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			alias_found = 1;
			break;
		}
	}
	if (!alias_found)
	{
		write(1, name, sizeof(name));
		write(1, "Not found", 1);
	}
}

/**
 * run_aliases - execute an alias
 * @argv: the list of alias
 * Return: 0 or -1
 */
int run_aliases(char **argv)
{
	int i, alias_found = 0, retVal = 0, j = 0, k = 0;
	char *tocken = NULL;
	char *args[32];

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, argv[0]) == 0)
		{
			alias_found = 1;
			tocken = _strtok(aliases[i].value, " ");
			while (tocken != NULL)
			{
				args[j++] = tocken;
				tocken = _strtok(NULL, " ");
			}

			while (argv[k++] != NULL)
			{
				args[j++] = argv[k];
			}

			args[j] = NULL;
			break;
		}
	}

	if (!alias_found)
		retVal = -1;
	else
		execute_command(args);

	return (retVal); /* return -1 if alias is not found and 0 else*/
}
