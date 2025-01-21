
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/i2c.h>

#define I2C_BUS 10
// I2C adapter struct
static struct i2c_adapter *fan_controller_i2c_adapter = NULL;
// I2C Client struct
static struct i2c_client *fan_controller_i2c_client = NULL;

// template struct for device creation
static struct i2c_board_info fan_control_i2c_board_info ={
    // macro initializes essential filed of the struct
    I2C_BOARD_INFO("Fan Controller", 0x2f),
};

static int fan_controller_probe(struct i2c_client *fan_controller_i2c_client, const struct i2c_device_id *id)
{
    printk("\n---------------------------Probing the module---------------------------\n");
    return 0;
}
static void fan_controller_remove(struct i2c_client *fan_controller_i2c_client)
{
    printk("\n---------------------------Removing the module---------------------------\n");
}

static const struct i2c_device_id fan_controller_id[] = {
    {"GPIO_Expander", 0},
    {},
};

MODULE_DEVICE_TABLE(i2c, fan_controller_id);

static struct i2c_driver fan_controller_driver = {
    .driver = {
        .name = "Fan_Controller",
        .owner = THIS_MODULE, 
    },
    .probe = gpio_expander_probe,
    .remove = gpio_expander_remove,
    .id_table = fan_controller_id,
};

static int __init fan_controller_init(void)
{
    printk("Init fan controller module\n");
    printk("Get fan controller get I2C adpater\n\n");
    fan_controller_i2c_adapter = i2c_get_adapter(I2C_BUS);
    printk("Get new client device\n\n");
    fan_controller_i2c_client = i2c_new_client_device(fan_controller_i2c_adapter, &fan_control_i2c_board_info);
    i2c_add_driver(&fan_controller_driver);
    i2c_put_adapter(fan_controller_i2c_adapter);
    return 0;
}

static void __exit fan_controller_exit(void)
{
    i2c_unregister_device(fan_controller_i2c_client);
    i2c_del_driver(&fan_controller_driver);
    printk("\n exiting module \n");
}

module_init(fan_controller_init);
module_exit(fan_controller_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting Module");
MODULE_AUTHOR("SJ Park");