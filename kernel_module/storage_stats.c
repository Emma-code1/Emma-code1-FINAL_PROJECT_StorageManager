#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static struct proc_dir_entry *entry;

static int show(struct seq_file *m, void *v) {
    seq_printf(m, "Read Operations: 0\n");
    seq_printf(m, "Write Operations: 0\n");
    return 0;
}

static int open_stats(struct inode *inode, struct file *file) {
    return single_open(file, show, NULL);
}

static const struct proc_ops ops = {
    .proc_open = open_stats,
    .proc_read = seq_read,
    .proc_release = single_release
};

static int __init init_mod(void) {
    entry = proc_create("storage_stats", 0, NULL, &ops);
    return 0;
}

static void __exit exit_mod(void) {
    proc_remove(entry);
}

module_init(init_mod);
module_exit(exit_mod);
MODULE_LICENSE("GPL");
