#import <Cordova/CDVPlugin.h>

@interface AppIconChanger : CDVPlugin

- (void) isSupported:(CDVInvokedUrlCommand*)command;
- (void) changeIcon:(CDVInvokedUrlCommand*)command;

@end
