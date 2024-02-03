import{_ as e}from"./_tslib-6e8ca86b.js";import{D as t,b as s,c as n,d as o,I as i}from"./text-editor-98535492.js";import{m as r}from"./mask-controller-6b09f135.js";import{t as u}from"./constants-4c28185b.js";import{s as d}from"./lit-element-b0a6fcba.js";import{e as l}from"./property-d3853089.js";import{n as p}from"./custom-element-bd7061f2.js";import"./dx-ui-element-de378e9d.js";import"./logicaltreehelper-15991dcb.js";import"./layouthelper-4b19d191.js";import"./rect-7fc5c2ef.js";import"./point-9c6ab88a.js";import"./lit-element-base-af247167.js";import"./data-qa-utils-8be7c726.js";import"./css-classes-f3f8ed66.js";import"./custom-events-helper-18f7786a.js";import"./eventhelper-8570b930.js";import"./disposable-d2c2d283.js";import"./dom-utils-7f5be2f0.js";import"./dom-166a04be.js";import"./key-59f0f3b5.js";var a;!function(e){e.isDisplayFormatDefined="is-display-format-defined",e.isPassword="is-password"}(a||(a={}));const c={...a,...t};let h=class extends s{constructor(){super(...arguments),this.selectionObserver=new MutationObserver(this.selectInputValue.bind(this)),this.boundOnInputFocusHandler=this.onInputFocusIn.bind(this),this.boundOnInputFocusOutHandler=this.onInputFocusOut.bind(this),this.boundOnInputPointerDownHandler=this.onPointerDown.bind(this),this.boundOnBeforeInputHandler=this.onBeforeInput.bind(this),this.boundOnInputKeyUpHandler=this.onInputKeyUp.bind(this),this.isDisplayFormatDefined=!1,this.isPassword=!1}get shouldProcessFocusIn(){return this.isDisplayFormatDefined}get shouldProcessFocusOut(){return this.isDisplayFormatDefined}get shouldProcessEnter(){return!1}get inputElement(){return this.fieldElement}get shouldProcessFieldTextVersion(){return!this.isPassword&&super.shouldProcessFieldTextVersion}onFieldReady(e,t){e.addEventListener("keyup",this.boundOnInputKeyUpHandler),e.addEventListener("beforeinput",this.boundOnBeforeInputHandler),e.addEventListener("focus",this.boundOnInputFocusHandler),e.addEventListener("focusout",this.boundOnInputFocusOutHandler),e.addEventListener("pointerdown",this.boundOnInputPointerDownHandler),super.onFieldReady(e,t),t&&this.focused&&this.onInputFocusIn()}onDispose(e){null==e||e.removeEventListener("keyup",this.boundOnInputKeyUpHandler),null==e||e.removeEventListener("beforeinput",this.boundOnBeforeInputHandler),null==e||e.removeEventListener("focus",this.boundOnInputFocusHandler),null==e||e.removeEventListener("focusout",this.boundOnInputFocusOutHandler),null==e||e.removeEventListener("pointerdown",this.boundOnInputPointerDownHandler),e&&r.dispose(e),super.onDispose(e)}onInputFocusIn(){this.shouldProcessFocusIn&&this.processFocusIn()}onInputFocusOut(e){this.shouldProcessFocusOut&&this.processFocusOut(e)}onInputKeyUp(e){this.processKeyUp(e)}onBeforeInput(e){this.processBeforeInput(e)}onPointerDown(e){super.onPointerDown(e),this.processPointerDown(e)}processKeyUp(e){return!1}processFocusIn(){if(!this.fieldElement)return;const e=0===this.fieldElement.selectionStart&&this.fieldElement.selectionEnd===this.fieldElementValue.length&&this.focused;this.selectionObserver.observe(this.fieldElement,{attributeFilter:["data-need-selection"]}),this.raiseFocusIn(e)}processFocusOut(e){this.raiseFocusOut(this.fieldElementValue)}processBeforeInput(e){return!1}processPointerDown(e){return!1}selectInputValue(){this.fieldElement&&this.focused&&(this.fieldElement.select(),this.fieldElement.removeAttribute("data-need-selection"),this.selectionObserver.disconnect())}raiseFocusIn(e){this.dispatchEvent(new n(e))}raiseFocusOut(e){this.dispatchEvent(new o(e))}raiseKeyDown(e){this.dispatchEvent(new i(e))}getFieldElement(){return this.querySelector("input")}selectInputText(e,t){this.fieldElement&&this.fieldElement.setSelectionRange(e,t)}selectAll(){this.fieldElement&&this.focused&&this.fieldElement.select()}onPasswordChanged(){this.isPassword&&(this.fieldElementValue="")}updated(e){this.rendered&&e.has("isPassword")&&this.onPasswordChanged(),super.updated(e)}};h.shadowRootOptions={...d.shadowRootOptions,delegatesFocus:!0},e([l({type:Boolean,attribute:a.isDisplayFormatDefined})],h.prototype,"isDisplayFormatDefined",void 0),e([l({type:Boolean,attribute:a.isPassword})],h.prototype,"isPassword",void 0),h=e([p(u)],h);const m={loadModule:function(){}};export{h as DxInputEditor,c as DxInputEditorAttributes,m as default};
