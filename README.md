# Cordova App Icon Changer
by [Eddy Verbruggen](http://twitter.com/eddyverbruggen)

<img src="https://github.com/EddyVerbruggen/cordova-plugin-app-icon-changer/raw/master/media/demo.gif" width="373px" height="688px" />

## Installation

```
$ cordova plugin add cordova-plugin-app-icon-changer
```

## API

> Make sure to wait for `deviceready` before using any of these functions.

### `isSupported`

Only iOS 10.3 and up support this feature, so you may want to check beforehand: 

```js
AppIconChanger.isSupported(
  function(supported) {
    console.log("Supported? " + supported);
  }
);
```

### `changeIcon`

To be able to switch to a different icon add it to your Xcode project as explained below and pass `iconName` to `changeIcon`.

Note 1: iOS will notify the user the icon changed, but this plugin allows you to suppress that message (it's the default even). It's probably not what Apple would like you to do, but no apps have been disapproved with suppression enabled.

Note 2: Changing the app icon is only allowed when the app is in the foreground, so forget about that weather app which silently updates its app icon.

```js
AppIconChanger.changeIcon(
    {
      iconName: "icon-phonegap",
      suppressUserNotification: true
    },
    function() { console.log("OK")},
    function(err) { console.log(err) }
);
```

## Preparing your app for icon switching
Apple doesn't allow switching to arbitrary icons, so they must be bundled with your app before releasing the app to the store.

Add the icons you'd like your users to be able to switch to for all relevant resolutions as usual.

> Note that you DON'T NEED to provide all those resolutions; you could get away with adding just the largest resolution and refer to it in the plist file. iOS will scale it down to other resolutions for you.

Drag the relevant icons to the Resources folder so it looks like this:

<img src="https://github.com/EddyVerbruggen/cordova-plugin-app-icon-changer/raw/master/media/xcode-config.png" width="725px" height="219px" />

The plist file can be edited in Xcode, or with your favorite text editor. If you use the latter you can copy-paste a snippet like the one below:

```xml
<plist>
<dict>

  <!-- Add or merge this bit -->
  <key>CFBundleIcons</key>
  <dict>
    <key>CFBundleAlternateIcons</key>
    <dict>
      <!-- The name you use in code -->
      <key>icon-phonegap</key>
      <dict>
        <key>UIPrerenderedIcon</key>
        <true/>
        <key>CFBundleIconFiles</key>
        <array>
          <!-- The actual filenames. Don't list the @2x/@3x files here, and you can use just the biggest one if you like -->
          <string>icon-phonegap-60</string>
        </array>
      </dict>
    </dict>
  </dict>

</dict>
</plist>
```

> Need iPad support as well? Just duplicate that plist config and change `<key>CFBundleIcons</key>` to `<key>CFBundleIcons~ipad</key>`.


## Changelog
* 1.0.0  Initial release.
