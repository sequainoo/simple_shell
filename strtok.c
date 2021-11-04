#include "shell.h"

/**
 * count_tokens - counts the number of tokens in a str
 * @str: the string to parse
 * Return: the number of tokens as an int;
 */
int count_tokens(char *str)
{
	int count = 1; /* every string at least has one token */
	int n_chars = 0;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		if (n_chars == 0 && *str == ' ')
		{
			++str;
			continue;
		}
		if (*str == ' ' && ((*(str + 1) != ' ') && (*(str + 1) != '\n')))
			count++;
		if (*str != ' ')
			n_chars++;
		++str;
	}

	return (count);
}

/**
 * malloc_tokens - allocates an array for token adresses
 * @size: the number of tokens to allocate for
 * Return: an array of token pointers
 */
char **malloc_tokens(size_t size)
{
	char **tokens = malloc(sizeof(char *) * size + 1);

	if (size == 0)
		return (NULL);

	if (tokens == NULL)
		return (NULL);

	tokens[size] = NULL;

	return (tokens);
}

/**
 * set_bounds - set the lower and upper boundary for the current token
 * taking into account preceeding space characters and contigous space chars
 * @current_lowerbound: the current lower boundary
 * @current_upperbound: the current upper boundary
 * Return: the number of characters as token
 */
int set_bounds(char **current_lowerbound, char **current_upperbound)
{
	char *lowerbound = *current_lowerbound;
	char *upperbound = *current_upperbound;
	int count = 0;

	while (*upperbound != '\0')
	{
		if (count == 0 && *upperbound == ' ')
		{
			++upperbound;
			continue;
		}
		if (*upperbound != ' ')
		{
			++count;
			++upperbound;
		}
		if (*upperbound == ' ')
			break;
	}
	*current_upperbound = upperbound;

	/* set lowerbound */
	while (*lowerbound != '\0')
	{
		if (*lowerbound == ' ')
		{
			++lowerbound;
			continue;
		}
		if (*lowerbound != ' ')
			break;
	}
	*current_lowerbound = lowerbound;

	return (count);
}

/**
 * parse_token - parse string into tokens
 * @str: the string to be parsed
 * @tokens: an array of tokens to be filled
 * @n_tokens: number of tokens to be parsed
 * Return: nothing
 */
void parse_token(char *str, char **tokens, int n_tokens)
{
	char *lowerbound = str, *upperbound = str;
	char *token = NULL;
	int n_chars; /* hold number of chars for each token */
	int n = 0, i = 0;

	while (n < n_tokens)
	{
		n_chars = set_bounds(&lowerbound, &upperbound);
		token = malloc(sizeof(char) * n_chars);

		i = 0;
		while (i < n_chars)
		{
			token[i++] = *lowerbound++;
		}
		token[i] = '\0';
		lowerbound = upperbound;
		*(tokens + n) = token;
		++n;
	}
	tokens[n] = NULL;
}

/**
 * _strtok - takes a string and separates into tokens
 * @str: string to tokenize
 * Return: a null terminated list of tokens
 */
char **_strtok(char *str)
{
	char **tokens = NULL;
	int n_tokens;

	n_tokens = count_tokens(str);
	tokens = malloc_tokens(n_tokens);
	if (tokens == NULL)
		return (NULL);

	parse_token(str, tokens, n_tokens);

	return (tokens);
}
