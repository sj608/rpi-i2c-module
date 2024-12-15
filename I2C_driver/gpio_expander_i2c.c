
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/i2c.h>

static struct i2c_adapter *gpio_expander_i2c_adapter = NULL;
static struct i2c_client *gpio_expander_i2c_client = NULL;