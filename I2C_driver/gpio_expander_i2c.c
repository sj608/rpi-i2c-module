
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/i2c.h>

#define I2C_BUS 10
// I2C adapter struct
static struct i2c_adapter *gpio_expander_i2c_adapter = NULL;
// I2C Client struct
static struct i2c_client *gpio_expander_i2c_client = NULL;

// template struct for device creation
static struct i2c_board_info gpio_expander_i2c_board_info ={
    // macro initializes essential filed of the struct
    I2C_BOARD_INFO("GPIO_Expander", 0x2f),
};

static int gpio_expander_probe(struct i2c_client *gpio_expander_i2c_client, const struct i2c_device_id *id)
{
    printk("\n---------------------------Probing the module---------------------------\n");
    return 0;
}
static void gpio_expander_remove(struct i2c_client *gpio_expander_i2c_client)
{
    printk("\n---------------------------Removing the module---------------------------\n");
}

static const struct i2c_device_id gpio_expander_id[] = {
    {"GPIO_Expander", 0},
    {},
};

MODULE_DEVICE_TABLE(i2c, gpio_expander_id);

static struct i2c_driver gpio_expander_driver = {
    .driver = {
        .name = "GPIO_Expander",
        .owner = THIS_MODULE, 
    },
    .probe = gpio_expander_probe,
    .remove = gpio_expander_remove,
    .id_table = gpio_expander_id,
};

static int __init gpio_expander_init(void)
{
    printk("Init gpio expander module\n");
    printk("Get gpio expander get I2C adpater\n\n");
    gpio_expander_i2c_adapter = i2c_get_adapter(I2C_BUS);
    printk("Get new client device\n\n");
    gpio_expander_i2c_client = i2c_new_client_device(gpio_expander_i2c_adapter, &gpio_expander_i2c_board_info);
    i2c_add_driver(&gpio_expander_driver);
    i2c_put_adapter(gpio_expander_i2c_adapter);
    return 0;
}

static void __exit gpio_expander_exit(void)
{
    i2c_unregister_device(gpio_expander_i2c_client);
    i2c_del_driver(&gpio_expander_driver);
    printk("\n exiting module \n");
}

module_init(gpio_expander_init);
module_exit(gpio_expander_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting Module");
MODULE_AUTHOR("SJ Park");