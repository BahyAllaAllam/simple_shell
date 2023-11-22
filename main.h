#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct list_str - liststr
 * @n: n
 * @s: s
 * @nex: next
*/
typedef struct list_str
{
	int n;
	char *s;
	struct list_str *nex;
} list_s;

/**
 * struct pas_inf - pass info
 * @ar: arg
 * @argv: argv
 * @pa: path
 * @argc: argc
 * @l_c: line count
 * @e_n: err num
 * @l_c_f: line count flag
 * @fn: f name
 * @e: env
 * @env: environ
 * @h: history
 * @alias: alias
 * @e_c: env changed
 * @s: status
 * @c_b: cmd_buf
 * @c_b_t: cmd buf type
 * @rfd: read fd
 * @hc: history count
*/
typedef struct pas_inf
{
	char *ar;
	char **argv;
	char *pa;
	int argc;
	unsigned int l_c;
	int e_n;
	int l_c_f;
	char *fn;
	list_s *e;
	list_s *h;
	list_s *alias;
	char **env;
	int e_c;
	int s;
	char **c_b;
	int c_b_t;
	int rfd;
	int hc;
} info_s;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct bu_in - built in
 *@t: type
 *@f: func
*/
typedef struct bu_in
{
	char *t;
	int (*f)(info_s *);
} bu_in_ta;

/* hsh.c */
int hsh(info_s *, char **);
int fi_bu_in(info_s *);
void fi_cm(info_s *);
void fo_cm(info_s *);

/* path.c */
int is_cm(info_s *, char *);
char *dup_chs(char *, int, int);
char *fi_pa(info_s *, char *, char *);

/* loophsh.c */
int lo_hs(char **);

/* err_string_functions.c */
void e_put_s(char *);
int e_put_char(char);
int pu_fd(char s, int f);
int pu_s_fd(char *s, int f);

/* string_functions.c */
int str_len(char *);
int str_cmp(char *, char *);
char *st_wi(const char *, const char *);
char *str_cat(char *, char *);

/* string_functions2.c */
char *str_cpy(char *, char *);
char *str_dup(const char *);
void put_s(char *);
int put_char(char);

/* string_functions3.c */
char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_chr(char *, char);

/* string_functions4.c */
char **str_tow(char *, char *);
char **str_tow2(char *, char);

/* memory_functions */
char *mem_set(char *, char, unsigned int);
void f_free(char **);
void *re_alloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int b_free(void **);

/* more_functions.c */
int inter_active(info_s *);
int is_de(char, char *);
int is_alpha(int);
int at_oi(char *);

/* more_functions2.c */
int err_at_oi(char *);
void pr_er(info_s *, char *);
int p_d(int, int);
char *con_num(long int, int, int);
void re_co(char *);

/* builtin_emulators.c */
int my_exit(info_s *);
int my_cd(info_s *);
int my_help(info_s *);

/* builtin_emulators2.c */
int my_hist(info_s *);
int my_alias(info_s *);

/* getline.c module */
ssize_t ge_in(info_s *);
int get_lin(info_s *, char **, size_t *);
void sig_int_Han(int);

/* info.c module */
void cle_in(info_s *);
void set_in(info_s *, char **);
void fre_in(info_s *, int);

/* env.c module */
char *get_env(info_s *, const char *);
int my_env(info_s *);
int my_set_env(info_s *);
int my_unset_env(info_s *);
int pop_env_lis(info_s *);

/* env2.c module */
char **ge_en(info_s *);
int un_set_env(info_s *, char *);
int set_env(info_s *, char *, char *);

/* file_io_functions.c */
char *get_his_fil(info_s *in);
int wri_his(info_s *in);
int rea_his(info_s *in);
int bui_his_lis(info_s *in, char *b, int lc);
int ren_his(info_s *in);

/* liststr.c module */
list_s *ad_no(list_s **, const char *, int);
list_s *ad_no_en(list_s **, const char *, int);
size_t pri_lis_str(const list_s *);
int del_nod_at_ind(list_s **, unsigned int);
void fre_lis(list_s **);

/* liststr2.c module */
size_t lis_len(const list_s *);
char **li_to_st(list_s *);
size_t pri_lis(const list_s *);
list_s *nod_sta_wit(list_s *, char *, char);
ssize_t get_nod_ind(list_s *, list_s *);

/* chain.c */
int is_ch(info_s *, char *, size_t *);
void che_cha(info_s *, char *, size_t *, size_t, size_t);
int repl_alia(info_s *);
int repl_vars(info_s *);
int repl_stri(char **, char *);

#endif

